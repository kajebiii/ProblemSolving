#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define mp make_pair
typedef pair<int, int> pi;
const int MAX_N = 15, MAX_V = MAX_N*MAX_N, INF = 0x7fffffff;
const pi Ch[4] = {mp(0, 1), mp(1, 0), mp(0, -1), mp(-1, 0)};
pi operator+(const pi &a, const pi &b) {return mp(a.first+b.first, a.second+b.second); }

int Nr[MAX_N][MAX_N], Dis[MAX_N][MAX_N];
int Exit[MAX_N][MAX_N][MAX_N*4], ExitN;
int N, M; char Mp[MAX_N][MAX_N];
void doInit()
{
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++) scanf("%s", Mp[i]+1);
	for(int i=1; i<=N; i++) Mp[i][0] = Mp[i][M+1] = 'X';
	for(int i=1; i<=M; i++) Mp[0][i] = Mp[N+1][i] = 'X';
	ExitN = 0;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
		if(Mp[i][j] == 'D') Nr[i][j] = ++ExitN;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) for(int t=1; t<=ExitN; t++)
		Exit[i][j][t] = 0;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
	{
		if(Mp[i][j] != '.') continue;
		for(int x=0; x<=N+1; x++) for(int y=0; y<=M+1; y++) Dis[x][y] = INF;
		queue<pi> Q; Q.push(mp(i, j)); Dis[i][j] = 0;
		while(!Q.empty())
		{
			pi now = Q.front(); Q.pop();
			if(Mp[now.first][now.second] == 'D')
			{
				Exit[i][j][Nr[now.first][now.second]] = Dis[now.first][now.second];
				continue;
			}
			for(int k=0; k<4; k++)
			{
				pi next = now + Ch[k];
				if(Mp[next.first][next.second] == 'X') continue;
				if(Dis[next.first][next.second] != INF) continue;
				Dis[next.first][next.second] = Dis[now.first][now.second] + 1;
				Q.push(next);
			}
		}
	}
}

bool Visit[MAX_N][MAX_N]; 
pi Match[MAX_N*4][MAX_V];
bool dfs(pi k, int maxT)
{
	int x = k.first, y = k.second;
	if(Visit[x][y]) return false;
	Visit[x][y] = true;
	for(int t=1; t<=maxT; t++)
		for(int i=1; i<=ExitN; i++)
		{
			if(Exit[x][y][i] != 0 && Exit[x][y][i] <= t)
				if(Match[i][t] == mp(0, 0) || dfs(Match[i][t], maxT))
				{
					Match[i][t] = k;
					return true;
				}
		}
	return false;
}
int main()
{
	int tc = 1;
	while(tc--)
	{
		doInit();
		int Ans = -1;
		for(int l=1, r=222; l<r; )
		{
			int m = (l+r) / 2;
			bool isCan = true;
			for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
			{
				if(Mp[i][j] != '.') continue;
				for(int x=1; x<=N; x++) for(int y=1; y<=M; y++)
					Visit[x][y] = false;
				if(!dfs(mp(i, j), m)) isCan = false;
			}
			for(int i=1; i<=ExitN; i++) for(int t=1; t<=m; t++)
				Match[i][t] = mp(0, 0);
			if(isCan) r = m;
			else l = m+1;
			Ans = l;
		}
		if(Ans != 222) printf("%d\n", Ans);
		else puts("impossible");
	}
	return 0;
}