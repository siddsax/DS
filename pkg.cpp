#include <bits/stdc++.h>

using namespace std;

long long int** multiply(long long int** A, long long int** B, long long int m)
{
	long long int** M;
	M = (long long int**)malloc(3*sizeof(long long int*));
	for (int i = 0; i < 3; ++i)
	{
		M[i]=(long long int*)malloc(3*sizeof(long long int));
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			M[i][j] = 0;
			for (int k = 0; k < 3; ++k)
			{
				M[i][j] = (M[i][j]%m + ((A[i][k]%m)*(B[k][j]%m))%m)%m;
			}
		}
	}
	return M;
}

long long int** mat_mul(long long int a, long long int b, long int c, long long int n, long long int m)
{
	if (n == 0)
	{
		long long int** M;
		M = (long long int**)malloc(3*sizeof(long long int*));
		for (int i = 0; i < 3; ++i)
		{
			M[i]=(long long int*)malloc(3*sizeof(long long int));
		}
		M[0][0] = 1%m, M[0][1] = M[0][2] = M[1][0] = 0, M[2][2] = 1%m, M[1][1] = 1%m, M[1][2] = M[2][0] = M[2][1] = 0;
		return M;
	}
	if (n % 2 == 0)
	{
		long long int** left = mat_mul(a,b,c,(n)/2,m);
		return multiply(left, left, m);
	}
	else
	{
		long long int** left = mat_mul(a,b,c,(n-1)/2,m);
		long long int** M;
		M = (long long int**)malloc(3*sizeof(long long int*));
		for (int i = 0; i < 3; ++i)
		{
			M[i]=(long long int*)malloc(3*sizeof(long long int));
		}
		M[0][0] = a%m, M[0][1] = b%m, M[0][2] = c%m, M[1][0] = M[2][2] = 1%m, M[1][1] = M[1][2] = M[2][0] = M[2][1] = 0;
		
		return multiply(multiply(left, left, m), M, m);
	}

}

//use scanint(variable) for integer input instead of scanf
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
	long long int a,b,c,m;
	long long int n;
	scanf("%lld%lld%lld%lld%lld", &a,&b,&c,&n,&m);
	if ((n==1) || (n==2))
	{
		printf("%lld\n", 1%m);
	}
	else
	{
		a%=m;
		b%=m;
		c%=m;
		long long int** M = mat_mul(a,b,c,n-2,m);
		long long int ans = ((M[0][0] + M[0][1])%m + M[0][2])%m;
		printf("%lld\n", ans);
	}
	}
	return 0;
}
