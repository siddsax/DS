#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

long long int fibloop(long long int n, long long int a, long long int b,long long int c, long long int m){
	if ( n==1 ) return 1;
	else if(n==2) return 1;
  else{
  	long long int last = 1,last_to_last = 1, current = 0;
  	for(long long int i = 3;i<=n;i++){
  		current = ((a*(last%m))%m + (b*(last_to_last%m)%m) + c)%m;
  		last_to_last = last;
  		last = current;
  	}
  	return last;
  }	
}
int main()
{
	long long int a,b,c,n,m,test_cases = 0;
	scanf("%lld",&test_cases);
	// const clock_t begin_time = clock();
	for(int i = 0;i<test_cases;i++){ 
		scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&n,&m);
		printf("%lld\n",fibloop	(n,a,b,c,m));
	}
	return 0;
}
