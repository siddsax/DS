#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

uint64_t fibrec(uint64_t n,uint64_t a,uint64_t b,uint64_t c,uint64_t m){
	if ( n==1 ) return 1;
	else if(n==2) return 1;
  else{
  	return ((a*(fibrec(n-1,a,b,c,m)%m)%m) + (b*(fibrec(n-2,a,b,c,m)%m)%m) + c)%m;
  }
}
uint64_t fibloop(uint64_t n, uint64_t a, uint64_t b,uint64_t c, uint64_t m){
	if ( n==1 ) return 1;
	else if(n==2) return 1;
  else{
  	uint64_t last = 1,last_to_last = 1, current = 0;
  	for(uint64_t i = 3;i<=n;i++){
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
uint64_t** alloc_mat(uint64_t r, uint64_t c){
	uint64_t** m = (uint64_t**)malloc(sizeof(uint64_t*)*r);
  for(uint64_t j = 0;j<r;j++){
  	*(m + j) = (uint64_t*)malloc(sizeof(uint64_t)*c);
  }
	return m;
}

uint64_t** matmul(uint64_t** mat_1,uint64_t** mat_2,uint64_t r1,uint64_t c1,uint64_t r2,uint64_t c2,uint64_t m){
  uint64_t** matout = alloc_mat(r1,c2);
	for(uint64_t i = 0; i < r1; ++i)
	      for(uint64_t j = 0; j < c2; ++j){
	          matout[i][j] = 0;
	          for(uint64_t k = 0; k < c1; ++k)
	            matout[i][j] += ((mat_1[i][k]%m) * (mat_2[k][j]%m))%m;
	        }
	return matout;          

}
uint64_t** matpow(uint64_t** matrix,uint64_t n,uint64_t dim,uint64_t m){
	if (n==1) return matrix;
	else{
	  uint64_t** m_1 = alloc_mat(dim,dim);
    m_1 = matpow(matrix,n/2,dim,m);
		uint64_t** m_2 = alloc_mat(dim,dim);
		m_2 = matmul(m_1,m_1,dim,dim,dim,dim,m);
		if(n%2==0) {
			return m_2;
		}	
		else {
			uint64_t** x = alloc_mat(dim,dim);
			x = matmul(m_2,matrix,dim,dim,dim,dim,m);
			return x;      
		}
  }
  
}
uint64_t fibmat(uint64_t n, uint64_t a, uint64_t b,uint64_t c,uint64_t m){
	if ( n==1 ) return 1;
	else if(n==2) return 1;
	else{
		uint64_t** matrix = alloc_mat(3,3);
	  uint64_t** matin = alloc_mat(3,1);
	  uint64_t** matout = alloc_mat(3,1);
	  matrix[0][0] = a,matrix[0][1] = b,matrix[0][2] = 1,matrix[1][0] = 1,matrix[1][1] = 0,matrix[1][2] = 0,matrix[2][0] = 0,matrix[2][1] = 0,matrix[2][2] = 1;
		matin[0][1] = 1,matin[1][1] = 1,matin[2][1] = c;
    uint64_t** x = alloc_mat(3,3);
		x = matpow(matrix,n-2,3,m);
    return (x[0][0] + x[0][1] + (c*x[0][2])%m)%m;
	}
}
uint64_t power (uint64_t a, uint64_t b){
    uint64_t result=1;
    for (int i = 0;i<b;i++){
        result*=a;
    }
    return result;
}
int main(int argc, char *argv[])
{
	uint64_t a,b,c,m,test_cases = 0;
	uint64_t n = 0;

	a = atol(argv[1]); // 3
	b = atol(argv[2]); // 4
	c = atol(argv[3]); // 7
	m = atol(argv[4]); // 5

	double time;
	// for(int i = 1;i<10;i++)
	// {	
	  uint64_t q = atol(argv[5]);
    const clock_t begin_time = clock();
		// printf("Matrix call : %ld\n",fibmat	(power(10,2*i),a,b,c,m));
		printf("Matrix call : %ld\n",fibmat	(q,a,b,c,m));
	  time = ((double)( clock () -  begin_time )) /  CLOCKS_PER_SEC ;
	  printf("n = ");
	  // printf("%" PRIu64 ,power(10,2*i));
	  printf("%" PRIu64 ,q);
	  printf(", time = %f \n",time);
  // }
	// return 0;
}
