#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int x; scanf("%d", &x);
		int past = 0, ans = 0;
		for(int i=0; i<8; i++)
		{
			int now = (x & (1<<i))?1:0;
			int bit = past ^ now;
			ans += (bit << i);
			past = bit;
		}
		printf("%d ", ans);
	}
	return 0;
}