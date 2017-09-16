#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef pair<int, int> pi;

const int MAX_N = 1e4 + 100, INF = 0x7fffffff;

int N, M, S, E, inD[MAX_N];
vector<pi> Ed[MAX_N], R[MAX_N];
vector<int> Dis;
vector<bool> Chk;

int main()
{
	scanf("%d%d", &N, &M);
	for(int _=0; _<M; _++)
	{
		int x, y, w; scanf("%d%d%d", &x, &y, &w);
		Ed[x].push_back(make_pair(y, w));
		 R[y].push_back(make_pair(x, w));
		inD[y]++;
	}
	scanf("%d%d", &S, &E);
	Dis = vector<int>(N+1, -INF);
	queue<int> Q; for(int i=1; i<=N; i++) if(inD[i] == 0) Q.push(i);
	Dis[S] = 0;

	while(!Q.empty())
	{
		int v = Q.front(); Q.pop();
		for(auto &t : Ed[v])
		{
			int w, c; tie(w, c) = t;
			Dis[w] = max(Dis[v] + c, Dis[w]);
			if(--inD[w] == 0)
				Q.push(w);
		}
	}


	int ans = 0;
	while(!Q.empty()) Q.pop(); Q.push(E);
	Chk = vector<bool>(N+1, false);
	while(!Q.empty())
	{
		int v = Q.front(); Q.pop();
		if(Chk[v]) continue; Chk[v] = true;
		for(auto &t : R[v])
		{
			int w, c; tie(w, c) = t;
			if(Dis[w] != -INF && Dis[w] + c == Dis[v]) 
			{
				ans++;
				if(Chk[w]) continue;
				Q.push(w);
			}
		}
	}
	printf("%d\n%d\n", Dis[E], ans);
	return 0;
}
