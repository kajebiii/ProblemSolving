#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef pair<int, int> pi;

const int MAX_N = 1e2 + 10, INF = 0x7fffffff;

int L, N, M;
vector<int> List;
vector<pi> Ed[MAX_N];
vector<int> Dis[MAX_N];

int main()
{
	int tc; scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d%d%d", &L, &N, &M);
		for(int i=0, x; i<L; i++) scanf("%d", &x), List.push_back(x);
		for(int i=0, x, y, w; i<M; i++)
		{
			scanf("%d%d%d", &x, &y, &w);
			Ed[x].push_back(make_pair(y, w));
			Ed[y].push_back(make_pair(x, w));
		}

		auto getDis = [&](int s)
		{
			vector<int> dis = vector<int>(N+1, INF);
			vector<bool> chk = vector<bool>(N+1, false);
			priority_queue<pi, vector<pi>, greater<pi> > Q;
			Q.push(make_pair(0, s)); dis[s] = 0;
			while(!Q.empty())
			{
				int v, d; tie(d, v) = Q.top(); Q.pop();
				if(chk[v] == true) continue;
				chk[v] = true;
				
				for(auto &t : Ed[v])
				{
					int w, c; tie(w, c) = t;
					if(chk[w]) continue;
					if(dis[w] > dis[v] + c)
						Q.push(make_pair(dis[w] = dis[v] + c, w));
				}
			}
			Dis[s] = dis;
		};
		for(int i=1; i<=N; i++) getDis(i);
		
		int ansIx = -1; long long ans = 1ll * INF * INF;
		for(int i=1; i<=N; i++)
		{
			long long now = 0;
			bool isCan = true;
			for(int x : List) 
			{
				if(Dis[i][x] == INF) {isCan = false; break;}
				now += 1ll * Dis[i][x] * Dis[i][x];
			}
			if(isCan && ans > now)
			{
				ans = now;
				ansIx = i;
			}
		}
		printf("%d %lld\n", ansIx, ans);

		//del
		[&]()
		{
			vector<int> temp;
			List.swap(temp);
			for(int i=1; i<=N; i++)
			{
				vector<pi> temps;
				Ed[i].swap(temps);
			}
		}
		();
	}
	return 0;
}