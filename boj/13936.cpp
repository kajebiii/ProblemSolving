#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 1e5 + 100, INF = 0x7fffffff;

int N, I, O;
vector<int> Is, Os;
vector<int> Ed[2][MAX_N]; // 1 means reverse;
vector<int> DI, DO, D;

void initGraph()
{
	scanf("%d%d%d", &N, &I, &O);
	for(int i=0, x; i<I; i++) scanf("%d", &x), Is.push_back(x);
	for(int i=0, x; i<O; i++) scanf("%d", &x), Os.push_back(x);
	for(int v=1; v<=N; v++)
	{
		int k; scanf("%d", &k);
		for(int i=0; i<k; i++)
		{
			int w; scanf("%d", &w);
			Ed[0][v].push_back(w);
			Ed[1][w].push_back(v);
		}
	}
}

void getDis(int g, vector<int> &first, vector<int> &dis)
{
	queue<int> Q;
	for(int i=1; i<=N; i++) dis[i] = -1;
	for(int v : first) Q.push(v), dis[v] = 0;

	while(!Q.empty())
	{
		int v = Q.front(); Q.pop();
		for(int w : Ed[g][v])
			if(dis[w] == -1)
			{
				dis[w] = dis[v] + 1;
				Q.push(w);
			}
	}
}
int main()
{
	initGraph();
	DI.reserve(N+1); DO.reserve(N+1); D.reserve(N+1);
	vector<int> start = vector<int>(1, 1);
	getDis(0, start, D);
	getDis(1, Is, DI);
	getDis(1, Os, DO);

	int ans = INF;
	for(int i=1; i<=N; i++)
	{
		if(DI[i] != -1 && DO[i] != -1 && D[i] != -1)
			ans = min(ans, DI[i] + DO[i] + D[i]);
	}
	if(ans == INF) puts("impossible");
	else printf("%d\n", ans);
	return 0;
}