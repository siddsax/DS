#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

// | G(n)  |   | a  b  1 | | G(n-1) |
// | G(n-1)| = | 1  0  0 | | G(n-2) |
// | c     |   | 0  0  1 | |  c     |
long long int** alloc_mat(long long int r, long long int c){
	long long int** m = (long long int**)malloc(sizeof(long long int*)*r);
  for(long long int j = 0;j<r;j++){
  	*(m + j) = (long long int*)malloc(sizeof(long long int)*c);
  }
	return m;
}

long long int** matmul(long long int** mat_1,long long int** mat_2,long long int r1,long long int c1,long long int r2,long long int c2,long long int m){
  long long int** matout = alloc_mat(r1,c2);
	for(long long int i = 0; i < r1; ++i)
	      for(long long int j = 0; j < c2; ++j){
	          matout[i][j] = 0;
	          for(long long int k = 0; k < c1; ++k)
	            matout[i][j] += ((mat_1[i][k]%m) * (mat_2[k][j]%m))%m;
	        }
	return matout;          

}
long long int** matpow(long long int** matrix,long long int n,long long int dim,long long int m){
	if (n==1) return matrix;
	else{
	  long long int** m_1 = alloc_mat(dim,dim);
    m_1 = matpow(matrix,n/2,dim,m);
		long long int** m_2 = alloc_mat(dim,dim);
		m_2 = matmul(m_1,m_1,dim,dim,dim,dim,m);
		if(n%2==0) {
			return m_2;
		}	
		else {
			long long int** x = alloc_mat(dim,dim);
			x = matmul(m_2,matrix,dim,dim,dim,dim,m);
			return x;      
		}
  }
  
}
long long int fibmat(long long int n, long long int a, long long int b,long long int c,long long int m){
	if ( n==1 ) return 1;
	else if(n==2) return 1;
	else{
		long long int** matrix = alloc_mat(3,3);
	  long long int** matin = alloc_mat(3,1);
	  long long int** matout = alloc_mat(3,1);
	  matrix[0][0] = a,matrix[0][1] = b,matrix[0][2] = 1,matrix[1][0] = 1,matrix[1][1] = 0,matrix[1][2] = 0,matrix[2][0] = 0,matrix[2][1] = 0,matrix[2][2] = 1;
		matin[0][1] = 1,matin[1][1] = 1,matin[2][1] = c;
    long long int** x = alloc_mat(3,3);
		x = matpow(matrix,n-2,3,m);
    return (x[0][0] + x[0][1] + (c*x[0][2])%m)%m;
	}
}

int main()
{
	long long int a,b,c,n,m,test_cases = 0;
	scanf("%lld",&test_cases);
	// const clock_t begin_time = clock();
	for(int i = 0;i<test_cases;i++){ 
		scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&n,&m);
		printf("%lld\n",fibmat	(n,a,b,c,m));
	}
	return 0;
}
