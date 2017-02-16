#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	struct node* prev_ptr;
	int data;
	struct node* next_ptr;
}node;

node insert(node* head, node* newnode, int n){
  for(int i=0;i<n;i++){
  	head = head->next_ptr;
  }
  node* temp = head->next_ptr;
  head->next_ptr = newnode;
  newnode->prev_ptr = head;
  newnode->next_ptr = temp; 
	// printf("aadadasd %d", head->next_ptr->data);
 
}
int main(){
	node *head, *newnode;
	head=(node*)malloc(sizeof(node*)*1);
  newnode=(node*)malloc(sizeof(node)*1);
  insert(head, newnode, 0);
  newnode->data = 5;
  printf(" %d\n", head->next_ptr->data);
}