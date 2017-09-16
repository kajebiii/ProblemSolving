#include <stdio.h>

typedef long long ll;
const int INF = 0x7fffffff, MAX_M = 1e4 + 100;
const ll LINF = 1ll * INF * 50;

int N, M, Nr[MAX_M];
ll getCnt(ll m)
{
	if(m < 0) return 0;
	ll cnt = 0;
	for(int i=0; i<M; i++)
		cnt += m / Nr[i] + 1;
	return cnt;
}
int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0; i<M; i++) scanf("%d", &Nr[i]);
	
	ll l = 0, r = LINF;
	while(l < r)
	{
		ll m = (l + r) >> 1;
		if(getCnt(m) >= N) r = m;
		else l = m + 1;
	}
	int cnt = N - getCnt(l-1);
	for(int i=0; i<M; i++)
	{
		if(l % Nr[i] == 0) cnt--;
		if(cnt == 0) {printf("%d\n", i+1); break; }
	}
	return 0;
}