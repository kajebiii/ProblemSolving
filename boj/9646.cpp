#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 9;

int N, W[MAX_N], M, H[MAX_N], K;
int Val[MAX_N][MAX_N];
int find(int a, int b)
{
	if(b > W[a]) return find(a+1, 1);
	if(a > N) return 1;

	int res = 0;
	for(int i=max(Val[a-1][b]+1, Val[a][b-1]); i<=K - (H[b] - a); i++)
	{
		Val[a][b] = i;
		res += find(a, b+1);
	}
	return res;
}
int main()
{
	while(scanf("%d", &N) == 1)
	{
		M = 0;
		for(int i=1; i<=N; i++) scanf("%d", &W[i]), M = max(M, W[i]);
		for(int i=1; i<=M; i++) H[i] = -1;
		for(int j=1; j<=M; j++) for(int i=1; i<=N; i++) if(W[i] >= j) H[j] = i;
		scanf("%d", &K);
		printf("%d\n", find(1, 1));
	}
	return 0;
}