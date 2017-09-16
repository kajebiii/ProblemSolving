#include <stdio.h>
#include <algorithm>
#include <tuple>
#include <queue>
#include <map>

using namespace std;

const int MAX_N = 6e1;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int> > pii;
#define mp make_pair

int N, M;
char Mp[MAX_N][MAX_N];
map<pii, int> Dis;
pi S;

pi operator+(const pi &a, const pi &b) {return mp(a.first+b.first, a.second+b.second); }
pi Ch[4] = {mp(-1, 0), mp(1, 0), mp(0, -1), mp(0, 1)};

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++) scanf("%s", Mp[i]);
	for(int i=0; i<N; i++) for(int j=0; j<M; j++)
		if(Mp[i][j] == '0') 
			S = mp(i, j), Mp[i][j] = '.';

	int ans = 0x7fffffff;
	queue<pii> Q; Q.push(mp(0, S)); Dis[mp(0, S)] = 1;
	while(!Q.empty())
	{
		pii now = Q.front(); Q.pop();
		int nowV = Dis[now];
		int st = now.first; pi co = now.second;
		if(Mp[co.first][co.second] == '1')
			ans = min(ans, nowV);
		for(int k=0; k<4; k++)
		{
			pi nco = co + Ch[k];
			int x = nco.first, y = nco.second;
			if(x<0 || y<0 || x>=N || y>=M) continue;
			if(Mp[x][y] == '#') continue;

			pii next;
			bool isCan = true;
			if(Mp[x][y] >= 'A' && Mp[x][y] <= 'F')
			{
				if(st & (1<<(Mp[x][y]-'A')))
					next = mp(st, nco);
				else 
					isCan = false;
			}
			else if(Mp[x][y] >= 'a' && Mp[x][y] <= 'f')
				next = mp(st | (1<<(Mp[x][y]-'a')), nco);
			else 
				next = mp(st, nco);

			if(isCan)
			{
				if(Dis[next] != 0) continue;
				Dis[next] = nowV + 1;
				Q.push(next);
			}
		}
	}

	if(ans == 0x7fffffff) puts("-1");
	else printf("%d\n", ans-1);
	return 0;
}