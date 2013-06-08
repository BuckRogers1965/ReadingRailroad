#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <buff.h>

size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp)
{
  buff handle = (buff *) userp;
  buffAdd(handle, buffer, nmemb*size); 
  return nmemb*size;
}

int main(void)
{
  CURL *curlhandle;
  CURLcode res;
  buff buffer;
  char * string;

  buffer = buffCreate(5000);
  curlhandle = curl_easy_init();

  if(curlhandle) {
    curl_easy_setopt(curlhandle, CURLOPT_URL, "http://rss.slashdot.org/Slashdot/slashdot");
    curl_easy_setopt(curlhandle, CURLOPT_FOLLOWLOCATION, 1L);

    /* pass all data to this function */
    curl_easy_setopt(curlhandle, CURLOPT_WRITEFUNCTION, write_data);

    /*    */
    curl_easy_setopt(curlhandle, CURLOPT_WRITEDATA, buffer); 

    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curlhandle);

    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    buffGetBuffer(buffer, &string);
    printf ("%s", string);
    /* always cleanup */
    curl_easy_cleanup(curlhandle);

  }
  return 0;
}
