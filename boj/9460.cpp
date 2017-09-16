#include <stdio.h>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;
const int MAX_N = 1e4 + 100, INF = 0x7fffffff;
int N, K;
pi Pt[MAX_N];
int main()
{
	int tc; scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d%d", &N, &K);
		for(int i=0; i<N; i++) scanf("%d%d", &Pt[i].first, &Pt[i].second);
		sort(Pt, Pt+N);
		int l = 0, r = INF;
		while(l < r)
		{
			int m = (1ll * l + r) >> 1;
			int cnt = 1, mnY = INF, mxY = -INF;
			for(int i=0; i<N; i++)
			{
				mnY = min(mnY, Pt[i].second);
				mxY = max(mxY, Pt[i].second);
				if(mxY - mnY > m) cnt++, mnY = mxY = Pt[i].second;
			}
			if(cnt <= K) r = m;
			else l = m + 1;
		}
		printf("%.1lf\n", l / 2.);
	}
	return 0;
}