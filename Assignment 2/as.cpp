#include <bits/stdc++.h>
using namespace std;
#define N 200005
int TOBALANCE=1; // TOBALANCE is 1 when the condition is Perfectly balanced, 0 otherwise. By changing this constant you can change balance 
                 //condition.
int NEARLY_BALANCED = 0;
int PERFECTLY_BALANCED = 1;
double BALANCE_RATIO = 0.75; //You may change this ratio.

/* structure of a node of the binary tree.
val: value at the node
size: size of subtree rooted at node
left,right:pointers to right and left sub tree 
*/
struct Node{
  int val;
  int size;
  struct Node *left,*right;
};

/*
This function takes a value and initialises and returns a new node whose value is set to the given parameter.
*/
Node* init(int val){
  Node *curr = (Node *)malloc(sizeof(Node));
  curr->val=val;
  curr->size=1;
  curr->left=curr->right=NULL;
  return curr;
}


/*
SortedArrayFromBST: This function takes as input a node, pointer to an array, and an integer that denotes the next free position in the array.
This function fills in the array all the values in the tree whose root is the given node i.e. output array finally contains the elements in 
increasing order.
This function must return the number of array positions it has filled. i.e. if initial value of parameter fst = p, then after returning from 
the function the final value must increase by the size of subtree i.e p+curr->size.
*/
int SortedArrayFromBST(Node *curr,int output[],int fst){

  if ( curr == NULL ){
    return 0;
  }
  int n=0;

  n = SortedArrayFromBST(curr->left,output,fst);

  fst += n;

  output[fst] = curr->val;
  fst++;
  n++;

  n += SortedArrayFromBST(curr->right,output,fst);

  return n;

}

/*
This function creates a BST from an array. It takes as parameters input array and the length of array. It returns the root of the BST
that is formed by the array
*/
Node *BSTFromSortedArray(int input[], int len){

  int index;

  index = len/2 ;
  
  Node *root = init( input[index] );

  root->size = len;

  if ( index > 0 ){

    root->left = BSTFromSortedArray( input , index );

  }

  if ( index < len-1 ){

    root->right = BSTFromSortedArray( input + index + 1 , len-1 - index );

  }

  return root;

}

/*
This function recursively deletes all the nodes in the tree whose root in pointed by curr
*/
void deleteNode(Node *curr){
  if(curr==NULL) return;
  deleteNode(curr->left);
  deleteNode(curr->right);
  delete curr;
}

/*
This function returns true if the current node satisfies the nearly balanced condition and false otherwise
*/
bool checkNearBalance(Node *curr){

  int max,leftsize=0 , rightsize=0;

  if( curr->left != NULL ){
    leftsize = curr->left->size;
  }

  if( curr->right != NULL ){
    rightsize = curr->right->size;
  }

  if( leftsize < rightsize ){
    max = rightsize;
  }
  else{
    max = leftsize;
  }

  if( max <= (int)( BALANCE_RATIO * (curr->size) ) ){
    return 1;
  }

  return 0;

}

/*
This function returns true if the current node satisfies the perfectly balanced condition and false otherwise
*/
bool checkPerfectBalance(Node *curr){
  //check if it is correct
  int h1 = 0, h2 = 0;

  Node *node;

  if( curr->left != NULL ){

    node = curr->left;
    while( node != NULL ){

      if ( node->left == NULL ){
        node = node->right;
        h1++;
        continue;
      }

      if ( node->right == NULL ){
        node = node->left;
        h1++;
        continue;
      }

      if ( node->left->size > node->right->size ){
        node = node->left;
        h1++;
        continue;
      }
      else{
        node = node->right;
        h1++;
        continue;
      }
      
    }

  }

  if( curr->right != NULL ){

    node = curr->right;
    while( node != NULL ){

      if ( node->left == NULL ){
        node = node->right;
        h2++;
        continue;
      }

      if ( node->right == NULL ){
        node = node->left;
        h2++;
        continue;
      }

      if ( node->left->size > node->right->size ){
        node = node->left;
        h2++;
        continue;
      }
      else{
        node = node->right;
        h2++;
        continue;
      }
      
    }

  }

  if( h1 < h2 ){
    if ( h2-h1 == 1 ){
      return 1;
    }
  }
  else{
    if ( h1-h2 <= 1 ){
      return 1;
    }
  }

  return 0;

}

/*
This function takes as input a pointer to a node and inserts a node in the subtree of the node depending on the value.
out[] array is used as a helper array which will be used when the BST does not satisfy the balanced condition.

-when the insert returns then the tree must satisfy the balanced condition
*/
void insert(Node *curr,int val,int out[]){

  Node *node,*prev_node;

  prev_node = curr;
  node = curr;
  
  while( node != NULL ){

    node->size = node->size + 1;

    if ( val < node->val ){
      prev_node = node;
      node = node->left;
    }
    else{
      prev_node = node;
      node = node->right;
    }
  }

  if( val < prev_node->val ){
    prev_node->left = init(val);
  }
  else{
    prev_node->right = init(val);
  }

  //***********NEED TO CHECK FOR BALANCED CONDITION AND BALANCE IT IT NEEDED

  

}

/*
This function takes as input a node pointer and a val and searches for a node which has value val in the subtree of node.
It returns true if the value is found, false otherwise.
*/
bool search(Node *curr,int val){

  if ( curr == NULL ){
    return 0;
  }

  if ( curr->val == val ){
    return 1;
  }

  return search( curr->left , val ) || search( curr->right , val );

}

int main(){
  Node *root = NULL;
  int out[N];
  int queries; scanf("%d",&queries);
  while(queries--){
    int c,val; scanf("%d%d",&c,&val);
    if(c==1){
      //insert
      if(root){
        insert(root,val,out);
      }else{
        root = init(val);
      }
    }else{
      //search query
      if(search(root,val)) printf("Yes\n"); else printf("No\n");
    }
  }
  return 1;
}
