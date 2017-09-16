#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 100, INF = 0x7fffffff;

int N, Nr[MAX_N], Sum[MAX_N];
int lMin[MAX_N], rMax[MAX_N];

int main()
{
	scanf("%d", &N); for(int i=1; i<=N; i++) scanf("%d", &Nr[i]), Sum[i] = Sum[i-1] + Nr[i];
	lMin[1] = min(0, Sum[1]); rMax[N] = Sum[N];
	for(int i=2; i<=N; i++) lMin[i] = min(lMin[i-1], Sum[i]), rMax[N-i+1] = max(rMax[N-i+2], Sum[N-i+1]);

	//not erase;
	int ans = -INF;
	for(int i=1; i<=N; i++)
		ans = max(ans, Sum[i] - lMin[i-1]);

	for(int i=2; i<=N-1; i++)
	{
		int lv = Sum[i-1] - lMin[i-2];
		int rv = rMax[i+1] - Sum[i];
		ans = max(ans, lv + rv);
	}
	printf("%d\n", ans);
	return 0;
}