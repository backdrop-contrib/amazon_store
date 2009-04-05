$Id$
Explanation of URLs and Browsenodes in the Search URL

When you land on the /amazon_store page with the no keywords, a BrowseNode is selected for you, depending
on the selected SearchIndex. If you have a SearchIndex selected, the browsenode is looked up and
results from that browsenode are shown. If you have no keywords, no searchindex, and no browsenode, it
just puts the keywords "Featured" and searches for it in searchIndex "All". Probably can do better than this.

Other items that can go on the URL:
MinimumPrice=
MaximumPrice=
MerchantId=
Brand=
SearchIndex=
Keywords=
Sort=
BrowseNode=

If you want a page with a specific set of things, without a search, you can just choose a BrowseNode:
http://example.com/amazon_store?BrowseNode=xxxxx

You can look at browsenodes at http://browsenodes.com

