#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

const int MAX_N = 1e2 + 10, INF = 0x7fffffff;
const long long LINF = 1ll * INF * INF;

typedef long long ll;

ll N, H, Nr[MAX_N], Dy[MAX_N][MAX_N * MAX_N * 2];
vector<ll> list;
int findNr(ll x)
{
	if(x < list.front()) return 0;
	if(x > list.back() ) return (int)list.size() - 1;
	int ix = lower_bound(list.begin(), list.end(), x) - list.begin();
	return ix;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%lld%lld", &N, &H);
		for(int i=1; i<=N; i++) scanf("%lld", &Nr[i]);
		if(abs(Nr[N] - Nr[1]) > H * (N-1)) {puts("impossible"); continue;}

		list.clear();
		for(int i=1; i<=N; i++) for(int j=1-N; j<=N-1; j++)
			list.push_back(Nr[i] + j * H);
		sort(list.begin(), list.end());
		list.resize(unique(list.begin(), list.end()) - list.begin());

		int HN = list.size();
		for(int i=1; i<=N; i++) for(int j=0; j<HN; j++) Dy[i][j] = LINF;
		Dy[1][findNr(Nr[1])] = 0;
		for(int i=2; i<N; i++)
		{
			for(int j=0, k=0; j<HN; j++)
			{
				while(list[j] - list[k] > H) k++;
				while(k+1 < HN && list[k+1] - list[j] <= H && Dy[i-1][k] >= Dy[i-1][k+1]) k++;
				if(Dy[i-1][k] != LINF) Dy[i][j] = Dy[i-1][k] + abs(Nr[i] - list[j]);
			}
		}

		ll ans = LINF;
		for(int l=findNr(Nr[N]-H), r=findNr(Nr[N]+H), i=l; i<=r; i++)
			ans = min(ans, Dy[N-1][i]);
		printf("%lld\n", ans);
	}
	return 0;
}