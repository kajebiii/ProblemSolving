#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef pair<int, int> pi;

int N, M;
vector<pi> R;
priority_queue<int, vector<int>, greater<int> > Q;

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		R.push_back(make_pair(x, x+y));
	}
	sort(R.begin(), R.end());
	int Ans = N;
	for(pi &t : R)
	{
		int x = t.first, y = t.second;
		int early = -1;
		while(!Q.empty())
		{
			int now = Q.top();
			if(now > x) break;
			if(x - now <= M) {early = now; Q.pop(); break; }
			Q.pop();
		}
		if(early == -1) Ans--;
		Q.push(y);
	}
	printf("%d\n", Ans);
	return 0;
}