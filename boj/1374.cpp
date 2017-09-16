#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

typedef pair<int, int> pi;

int N; vector<pi> List;

int main()
{
	scanf("%d", &N); for(int i=0, x, y, t; i<N; i++) scanf("%d%d%d", &t, &x, &y), List.push_back(make_pair(x, y));
	sort(List.begin(), List.end());
	priority_queue<int, vector<int>, greater<int> > Q;
	for(int i=0; i<N; i++)
	{
		if(!Q.empty() && Q.top() <= List[i].first) Q.pop();
		Q.push(List[i].second);
	}
	int ans = 0; while(!Q.empty()) Q.pop(), ans++;
	printf("%d\n", ans);
	return 0;
}
