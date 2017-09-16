#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 3e4 + 100;
typedef long long ll;

const int INF = 0x7fffffff;

int N, Nr[MAX_N], Sum[MAX_N];
ll SumL[MAX_N], SumR[MAX_N];
bool notP[MAX_N];
vector<int> P;
int getSum(int a, int b) {return Sum[b] - Sum[a-1]; }
ll getSideSum(int a, int b, int arrow) // 0 L, 1 R
{
	ll now;
	if(arrow == 0)
	{
		now = SumL[b] - SumL[a-1];
		now -= 1ll * getSum(a, b) * (N-b);
	}
	else
	{
		now = SumR[a] - SumR[b+1];
		now -= 1ll * getSum(a, b) * (a-1);
	}
	return now;
}
int main()
{
	for(int i=2; i<=30000; i++)
		if(notP[i] == false)
		{
			for(int j=i*2; j<=30000; j+=i) notP[j] = true;
			P.push_back(i);
		}
	while(1)
	{
		scanf("%d", &N);
		if(N == 0) break;
		for(int i=1; i<=N; i++) scanf("%d", &Nr[i]), Sum[i] = Sum[i-1] + Nr[i];
		for(int i=1; i<=N; i++) 
			SumL[i] = SumL[i-1] + 1ll * (N+1-i) * Nr[i];
		SumR[N+1] = 0;
		for(int i=N; i>=1; i--)
			SumR[i] = SumR[i+1] + 1ll * i * Nr[i];

		ll ans = 1ll * INF * INF;
		for(int i=1; i<=N; i++) 
			ans = min(ans, getSideSum(1, i-1, 0) + getSideSum(i+1, N, 1));
		for(int i=1; i<=N-2; i++) 
			ans = min(ans, getSideSum(1, i-1, 0) + Nr[i+1] + getSideSum(i+3, N, 1));
		for(int x=1; x<P.size(); x++)
		{
			int oddP = P[x];
			for(int i=1, mid; i<=N-oddP; i++)
			{
				mid = i+oddP/2;
				ans = min(ans, getSideSum(1, i-1, 0) +
					+getSideSum(i+1, mid, 1) + getSideSum(mid+1, i+oddP-1, 0)
					+getSideSum(i+oddP+1, N, 1));
			}
			if(notP[oddP+2] == true) continue;
			for(int i=1, mid; i<=N-2-oddP; i++)
			{
				mid = i+2+oddP/2;
				ans = min(ans, getSideSum(1, i-1, 0) + Nr[i+1] +
					+getSideSum(i+2+1, mid, 1) + getSideSum(mid+1, i+2+oddP-1, 0)
					+getSideSum(i+2+oddP+1, N, 1));
				mid = i+oddP/2;
				ans = min(ans, getSideSum(1, i-1, 0) + Nr[i+oddP+1] +
					+getSideSum(i+1, mid, 1) + getSideSum(mid+1, i+oddP-1, 0)
					+getSideSum(i+2+oddP+1, N, 1));
			}
			if(notP[oddP+4] == true) continue;

			for(int i=1, mid; i<=N-4-oddP; i++)
			{
				mid = i+2+oddP/2;
				ans = min(ans, getSideSum(1, i-1, 0) + Nr[i+1] +
					+ getSideSum(i+2+1, mid, 1) + getSideSum(mid+1, i+2+oddP-1, 0)
					+ Nr[i+2+oddP+1]
					+ getSideSum(i+4+oddP+1, N, 1));
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}