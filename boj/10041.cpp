#include <stdio.h>
#include <algorithm>

using namespace std;

int W, H, N;
int main()
{
	scanf("%d%d%d", &W, &H, &N);
	int pX, pY; scanf("%d%d", &pX, &pY);
	int ans = 0;
	for(int i=1; i<N; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		int a = x - pX, b = y - pY;
		if(a < 0) a *= -1, b *= -1;
		if(b >= 0) ans += max(a, b);
		else ans += a + abs(b);
		pX = x, pY = y;
	}
	printf("%d\n", ans);
	return 0;
}