<?php
//$Id$
/**
 @file
	Template for the the BrowseNodes content_type panel for an amazon product page
*/

if ($item->BrowseNodes->BrowseNode) {

  $ProductGroup = (string)$item->ItemAttributes->ProductGroup;
  $SearchIndex=ProductGroup2SearchIndex($ProductGroup);

  print "<ul>";
  foreach ($item->BrowseNodes->BrowseNode as $BrowseNode) {
    $item = $BrowseNode;
    $line = "";
    do {
      // If it has a paren in it, it's a consolidation node, and
      // not useful to end-user
      if (strstr($item->Name,"(")) {
        $line = "";
        break;
      }

      $line .= "<a href='/amazon_store/?BrowseNode={$item->BrowseNodeId}&SearchIndex={$SearchIndex}'>{$item->Name}</a> : ";
    } while ($item = $item->Ancestors->BrowseNode);
    if (strlen($line)) {
      print "<li>$line</li>";
    }
  }
  print "</ul>";

}