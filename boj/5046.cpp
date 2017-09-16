#include <stdio.h>
#include <algorithm>

using namespace std;

int N, B, H, W;
int main()
{
	scanf("%d%d%d%d", &N, &B, &H, &W);
	int ans = B + 1;
	for(int i=0; i<H; i++)
	{
		int k; scanf("%d", &k);
		for(int j=0, x; j<W; j++)
		{
			scanf("%d", &x);
			if(x >= N) ans = min(ans, k*N);
		}
	}
	if(ans == B+1) puts("stay home");
	else printf("%d\n", ans);
	return 0;
}