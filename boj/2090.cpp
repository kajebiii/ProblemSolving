#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 11;

ll ggcd(ll a, ll b) {return b?ggcd(b, a%b):a;}
int N; ll Nr[MAX_N];

int main()
{
	ll multi = 1, under = 0;
	scanf("%d", &N); for(int i=1; i<=N; i++) scanf("%lld", &Nr[i]), multi *= Nr[i];
	for(int i=1; i<=N; i++) under += multi / Nr[i];
	ll gcd = ggcd(multi, under);
	printf("%lld/%lld\n", multi/gcd, under/gcd);
	return 0;
}