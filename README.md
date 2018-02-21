Amazon store
=======================

Amazon shopping cart and searching

Installation
------------

1. Install and enable the module as usual. Requires the Amazon module.
2. Configure the various items in admin->config->Amazon Settings->Amazon. 
3. Make sure you're running cron, or the store's inventory will get hopelessly 
out of date with the actual Amazon inventory.
4. Configure the various items in admin->settings->Amazon Settings->amazon store. 
5. Optionally enable and configure the Item Page layout. A default block is provided.

Theming
-------

Most of the critical elements of display have template files.

You can just copy the template file to your theme
and modify it to suit. 

For example, if you'd like to change the search results page,
simply copy amazon_store_search_results.tpl.php to your
theme directory and modify.

The Item display page also has a complete blocks implementation.
You can enable the block and then mix and match blocks
to suit.


Using Browsenodes with the Amazon Store module
----------------------------------------------

You can easily get a list of related items under a particular browsenode
in the Amazon hierarchy. You just need to find the browsenode you want.

To find a browsenode, use the information at http://browsenodes.com
You can also use the browsenodes block optionally provided with
amazon_store to see browsenodes related to a particular product.

When you have a browsenode, you can use a URL like
http://example.com/amazon_store/?BrowseNode=319596011
to display all the items in that browsenode.

The browsenodes.com FAQ is useful: http://www.browsenodes.com/page-FAQ.html,
as is the article "Are Browsenodes disappearing" at 
http://www.a2sdeveloper.com/page-are-more/browse-nodes-disappearing.html


Browsenodes
-----------

Explanation of URLs and Browsenodes in the Search URL

When you land on the /amazon_store page with the no keywords, a BrowseNode is 
selected for you, depending on the selected SearchIndex. If you have a 
SearchIndex selected, the browsenode is looked up and results from that 
browsenode are shown. If you have no keywords, no searchindex, and no 
browsenode, it just puts the keywords "Featured" and searches for it in 
searchIndex "All". Probably can do better than this.

Other items that can go on the URL:
- MinimumPrice=
- MaximumPrice=
- Brand=
- SearchIndex=
- Keywords=
- Sort=  (try the sorts you see as you try out the interface)
- BrowseNode=  (a numeric browsenode - find what you're looking for on browsenode.com)
- ItemIid=  (a comma-delimited list of ASINs)

If you want a page with a specific set of things, without a search, you can 
just choose a BrowseNode:
http://example.com/amazon_store?BrowseNode=xxxxx
or
http://example.com/amazon_store?ItemId=ASIN1,ASIN2,ASIN3,ASIN4,ASIN5

You can look at browsenodes at http://browsenodes.com


License
-------

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.

Maintainers
-----------

- https://github.com/docwilmot/

Originally written for Drupal by

- https://www.drupal.org/u/rfay

This module is seeking additional maintainers.
