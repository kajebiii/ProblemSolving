#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int H, M, S, now = 0;
	scanf("%d%d%d", &H, &M, &S);
	now = H * 60 * 60 + M * 60 + S;
	int tc; scanf("%d", &tc);
	while(tc--)
	{
		int t, x;
		scanf("%d", &t);
		if(t<=2) scanf("%d", &x);
		if(t == 1) now += x;
		if(t == 2) now -= x;
		now = (now % (60 * 60 * 24) + (60 * 60 * 24)) % (60 * 60 * 24);
		if(t == 3)
			printf("%d %d %d\n", now/(60*60), (now%3600) / 60, (now%60));
	}
	return 0;
}