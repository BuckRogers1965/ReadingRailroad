ReadingRailroad
===============

aka Reader Replacement


This is a project that is being created in response to Google announcing the end of Google Reader, a project that I have used daily for many years. 

A service like this has the oportunity to grow to be a very nice social media replacement and a powerful search engine that is aimed directly at what people care about.

RR will have two phases. Phase one is to write a server that can read a series of rss feeds and store them in a database.  The list of feeds will be stored on the server as well. Phase two is to write the user interface as a web service so that a user can add log into their account, add feeds and see the list of posts sorted by feed.

Server:

  Phase 1, read in a single hard coded rss feed.
  Phase 2, process the rss feed using libxml2.
  Phase 3, store the elements of the feed in a database
  Phase 4, remove duplicates
  Phase 5, read a series of feeds from the database and store each.

Web Client:

  Phase 1, Login users
  Phase 2, allow users to add and remove feeds
  Phase 3, show users their feeds
  Phase 4, markup feeds, share feeds with other users.


