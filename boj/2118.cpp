#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 5e4 + 100, INF = 0x7fffffff;

int N, Nr[MAX_N * 2];
int main()
{
	scanf("%d", &N);
	int sum = 0;
	for(int i=0; i<N; i++) scanf("%d", &Nr[i]), Nr[i+N] = Nr[i], sum += Nr[i];
	int j = 0, now = 0;
	int ans = -1;
	for(int i=0; i<N; i++)
	{
		j = max(i, j);
		while(j < 2*N && now + Nr[j] <= sum / 2) now += Nr[j++];
		ans = max(ans, now);
		if(i < j) now -= Nr[i];
	}
	printf("%d\n", ans);
	return 0;
}