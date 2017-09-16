#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	char data[555], *p;
	while(scanf("%s", data) == 1)
	{
		p = data;
		int cnt, nr;
		while(sscanf(p, "%2x%n", &cnt, &nr) == 1)
		{
			printf("%c", cnt);
			p += nr;
		}
		puts("");
	}
	return 0;
}