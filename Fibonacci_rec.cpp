#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
long int fibrec(long int n,long int a,long int b,long int c,long int m){
	if ( n==1 ) return 1;
	else if(n==2) return 1;
  else{
  	return ((a*(fibrec(n-1,a,b,c,m)%m)%m) + (b*(fibrec(n-2,a,b,c,m)%m)%m) + c)%m;
  }
}
long int fibloop(long int n, long int a, long int b,long int c, long int m){
	if ( n==1 ) return 1;
	else if(n==2) return 1;
  else{
  	long int last = 1,last_to_last = 1, current = 0;
  	for(long int i = 3;i<=n;i++){
  		current = ((a*(last%m))%m + (b*(last_to_last%m)%m) + c)%m;
  		last_to_last = last;
  		last = current;
  	}
  	return last;
  }	
}
// | G(n)  |   | a  b  1 | | G(n-1) |
// | G(n-1)| = | 1  0  0 | | G(n-2) |
// | c     |   | 0  0  1 | |  c     |
long int** alloc_mat(long int r, long int c){
	long int** m = (long int**)malloc(sizeof(long int*)*r);
  for(long int j = 0;j<r;j++){
  	*(m + j) = (long int*)malloc(sizeof(long int)*c);
  }
	return m;
}

long int** matmul(long int** mat_1,long int** mat_2,long int r1,long int c1,long int r2,long int c2,long int m){
  long int** matout = alloc_mat(r1,c2);
	for(long int i = 0; i < r1; ++i)
	      for(long int j = 0; j < c2; ++j){
	          matout[i][j] = 0;
	          for(long int k = 0; k < c1; ++k)
	            matout[i][j] += ((mat_1[i][k]%m) * (mat_2[k][j]%m))%m;
	        }
	return matout;          

}
long int** matpow(long int** matrix,long int n,long int dim,long int m){
	if (n==1) return matrix;
	else{
	  long int** m_1 = alloc_mat(dim,dim);
    m_1 = matpow(matrix,n/2,dim,m);
		long int** m_2 = alloc_mat(dim,dim);
		m_2 = matmul(m_1,m_1,dim,dim,dim,dim,m);
		if(n%2==0) {
			return m_2;
		}	
		else {
			long int** x = alloc_mat(dim,dim);
			x = matmul(m_2,matrix,dim,dim,dim,dim,m);
			return x;      
		}
  }
  
}
long int fibmat(long int n, long int a, long int b,long int c,long int m){
	if ( n==1 ) return 1;
	else if(n==2) return 1;
	else{
		long int** matrix = alloc_mat(3,3);
	  long int** matin = alloc_mat(3,1);
	  long int** matout = alloc_mat(3,1);
	  matrix[0][0] = a,matrix[0][1] = b,matrix[0][2] = 1,matrix[1][0] = 1,matrix[1][1] = 0,matrix[1][2] = 0,matrix[2][0] = 0,matrix[2][1] = 0,matrix[2][2] = 1;
		matin[0][1] = 1,matin[1][1] = 1,matin[2][1] = c;
    long int** x = alloc_mat(3,3);
		x = matpow(matrix,n-2,3,m);
    return x[0][0] + x[0][1] + (c*x[0][2])%m;
	}
}
int main()
{
	long int a,b,c,n,m = 0;
	scanf("%ld",&n);
	scanf("%ld",&a);
	scanf("%ld",&b);
	scanf("%ld",&c);
	scanf("%ld",&m);
	// printf("Recursive call : %ld\n",fibrec(n,a,b,c));
	// printf("Loop call : %ld\n",fibloop	(n,a,b,c));
	printf("Matrix call : %ld\n",fibmat	(n,a,b,c,m));
	long int** mat_1;
	long int** mat_2;
	return 0;
}