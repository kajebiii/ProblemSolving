#include <stdio.h>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

int N;

int getP(int n)
{
	pi now = make_pair(1, 1);

	int period = -1;
	for(int i=1; ; i++)
	{
		pi next = make_pair((now.second), (now.second + now.first) % n);
		if(next.first == 1 && next.second == 1)
		{
			period = i;
			break;
		}
		now = next;
	}
	return period;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int t, n; scanf("%d%d", &t, &n);
		printf("%d %d\n", t, getP(n));
	}
	return 0;
}