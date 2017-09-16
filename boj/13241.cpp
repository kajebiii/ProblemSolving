#include <stdio.h>

typedef long long ll;

ll A, B;
ll gcd(ll x, ll y){return y==0?x:gcd(y, x%y);}

int main()
{
	scanf("%lld%lld", &A, &B);
	printf("%lld\n", A/gcd(A, B)*B);
	return 0;
}