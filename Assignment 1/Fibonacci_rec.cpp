#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
long long int fibrec(long long int n,long long int a,long long int b,long long int c,long long int m){
	if ( n==1 ) return 1;
	else if(n==2) return 1;
  else{
  	return ((a*(fibrec(n-1,a,b,c,m)%m)%m) + (b*(fibrec(n-2,a,b,c,m)%m)%m) + c)%m;
  }
}
int main()
{
	long long int a,b,c,n,m,test_cases = 0;
	scanf("%lld",&test_cases);
	// const clock_t begin_time = clock();
	for(int i = 0;i<test_cases;i++){ 
		scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&n,&m);
		printf("%lld\n",fibrec(n,a,b,c,m));
	}
	return 0;
}
