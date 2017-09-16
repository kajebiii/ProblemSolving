#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e2 + 10;

int N, M, K;
double Data[MAX_N];
int main()
{
	scanf("%d%d%d", &N, &M, &K);
	for(int o=1; o<=M; o++)
	{
		int x; double y;
		for(int i=1; i<=N; i++)
		{
			scanf("%d%lf", &x, &y);
			Data[x] = max(Data[x], y);
		}
	}
	sort(Data+1, Data+N+1);
	double ans = 0;
	for(int i=1; i<=K; i++) ans += Data[N-i+1];
	printf("%.1lf\n", ans);
	return 0;
}