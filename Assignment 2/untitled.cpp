  node = curr;
  int len;

  if((PERFECTLY_BALANCED&&(!checkPerfectBalance(node)))||(NEARLY_BALANCED&&(!checkNearBalance(node))))
  {
    printf("BOOM %d\n",node->val);
    len = SortedArrayFromBST(node,out,0);
    curr = BSTFromSortedArray(out,len);
    return;
  }
  while( node != NULL )
  {  
    if ( val < node->val )
    {
      prev_node = node;
      node = node->left;
      if((PERFECTLY_BALANCED&&(!checkPerfectBalance(node)))||(NEARLY_BALANCED&&(!checkNearBalance(node))))
      {
        printf("BOOM %d\n",node->val);
        len = SortedArrayFromBST(node,out,0);
        prev_node->left = BSTFromSortedArray(out,len);
        break;
      }  
    }
    else 
    {
      prev_node = node;
      node = node->right;
      if((PERFECTLY_BALANCED&&(!checkPerfectBalance(node)))||(NEARLY_BALANCED&&(!checkNearBalance(node))))
      {
        printf("BOOM %d\n",node->val);
        len = SortedArrayFromBST(node,out,0);
        prev_node->right = BSTFromSortedArray(out,len);
        break;
      }  
    }

  }
