#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e3 + 10;

int N, C;
int Nr[MAX_N];

int main()
{
	scanf("%d%d", &N, &C);
	for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
	int ans = 0;
	for(int s=1; s<=N; s++)
	{
		int now = C, cnt = 0;
		for(int i=s; i<=N; i++)
			if(now >= Nr[i]) now -= Nr[i], cnt++;
		ans = max(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}