#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>    // std::min

void scanArray(int* array, int n)
{
	for (int i = 0;i<n;i++)
	{		
		scanf("%d",(array+i));
	}	
}
int findMin(int* array, int n)
{
  int min = *(array);
	for (int i = 1;i<n;i++)
	{
		if(*(array+i)<min) min = *(array+i);
	}
	return min;
}
int main()
{
	int n;
	scanf("%d",&n);
	int* array = (int*)malloc(sizeof(int)*n);

	scanArray(array,n);
	int** matrix = (int**)malloc(sizeof(int*)*n);
  for (int i = 0;i<n;i++)
  {
  	int m = ceil(log2(n-i)); 
  	printf("%d",i);
  	*(matrix + i) = (int*)malloc(sizeof(int*)*m);
  	for(int j = 0;j<m;j++)
  	{
  	  *(*(matrix + i)+j) = findMin(array+i, pow(2,j));
  	}	
  }	
  for(int i=0;i<n;i++)
  {
  	for(int j=i;j<n;j++)
  	{
  		int var = floor(log2(j+1-i));
  		printf("%d %d", *(*(matrix + i)+var),*(*(matrix + j-(int)pow(2,var))+var));
  		int minimum = std::min(*(*(matrix + i)+var),*(*(matrix + j-(int)pow(2,var))+var));
  		printf("min between %dth and %dth is %d",i,j,minimum);
  	}	
  }	
}
