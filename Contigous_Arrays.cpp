#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
int* scan_arr(int* arr,int n)
{
	int placeholder = 0;
	for(int i = 0;i<n;i++)
  {
  	scanf("%d",arr + i);
  	// *(arr + i) = cin.get(); 
  }	
  return arr;
}

int main()
{
	printf("asa");
  int n = 0;
  scanf("%d",&n);
  // n = cin.get
  int* arr = (int*)malloc(sizeof(int)*n);
  scan_arr(arr,n);
  int last_sum;
  last_sum = *arr;
  int max = *arr;
  for(int i = 1;i<n;i++)
  {
  	if(last_sum > 0) last_sum = *(arr+i) + last_sum;
  	else last_sum = *(arr+i);  	
  	if(last_sum > max) max = last_sum;
  } 
  printf("%d\n",last_sum);
  // int sum_1 = *arr;
  // int sum_2 = *(arr+1);
  // int placeholder;
  // for(int i = 2;i<n;i++)
  // {
  //   if(*(arr+i)>0)
  //   {
  //   	placeholder = sum_2;
  //   	sum_2 = sum_1 + *(arr+i);
  //   	sum_1 = placeholder;

    // } 
  // }	
  return 0;
}