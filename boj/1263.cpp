#include <stdio.h>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

typedef pair<int, int> pi;

const int MAX_N = 1e3 + 10;

priority_queue<pi> Q;

int N, Nr[MAX_N][2];
int main()
{
	scanf("%d", &N); for(int i=0, x, y; i<N; i++) scanf("%d%d", &x, &y), Q.push(make_pair(y, x));
	int last = 0x7fffffff;
	while(!Q.empty())
	{
		pi now = Q.top(); Q.pop();
		last = min(last, now.first);
		last -= now.second;
	}
	if(last < 0) last = -1;
	printf("%d\n", last);
	return 0;
}