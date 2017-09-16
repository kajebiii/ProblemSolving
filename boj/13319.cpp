#include<stdio.h>
#include<stdlib.h>
#include<cassert>
#include <vector>

using namespace std;

typedef long long ll;

ll mul(ll n, ll m, ll M){
	if( !m ) return 0;
	if( m&1 ) return (n + mul(n*2%M, m/2, M)) % M;
	else return mul(n*2%M, m/2, M);
}

ll pw(ll n, ll m, ll M){
	ll ans = 1;
	while(m){
		if( m%2 == 1 ) ans = mul(ans, n, M);
		n = mul(n, n, M); m /= 2;
	}
	return ans;
}

int PN = 10000;
bool notP[100001];
vector<int> P;
int main()
{
	for(int i=2; i<=PN; i++)
	{
		if(notP[i] == true) continue;
		if(i > 500) P.push_back(i);
		for(int j=i*2; j<=PN; j+=i) notP[j] = true;
	}

	bool flag = false;
	ll n, m;
	for(int x : P) for(int y : P) for(int z : P)
	{
		if(x >=  y || y >= z) continue;
		ll k = 1ll * x * y * z - 1;
		if(k % (x-1) == 0 && k % (y-1) == 0 && k % (z-1) == 0)
		{
			n = k + 1;
			m = x;
			printf("%lld %d\n", n, m);
			return 0;
		}
	}
	//5816382001 521
//	assert(scanf("%lld%lld", &n, &m) == 2);
//	assert( 500 < n && n <= 1e15 && 2 <= m && m < n && n%m == 0);
	for(int i = 2; i <= 500; i++){
		assert( pw(i, n-1, n) == 1 );
	}
	return 0;
}
