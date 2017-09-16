#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

const int MAX_N = 5e3, MOD = 1e6, MAX_T = 300, INF = 0x7fffffff;

int T, N, A, B;
map<int, int> Mp;
int Dy[MAX_T][MAX_N];

int main()
{
	scanf("%d%d%d%d", &T, &N, &A, &B);
	for(int i=0, x; i<N; i++) scanf("%d", &x), Mp[x]++;
	Dy[0][0] = 1;

	int ans = 0;
	int cnt = 0;
	for(auto &p : Mp)
	{
		cnt++;
		int c = p.second;
		for(int l=0; l<=c; l++) for(int i=l; i<=N; i++)
			Dy[cnt][i] += Dy[cnt-1][i-l], Dy[cnt][i] %= MOD;
	}
	for(int i=A; i<=B; i++)
		ans += Dy[cnt][i], ans %= MOD;
	printf("%d\n", ans);
	return 0;
}