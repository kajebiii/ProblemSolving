// =====================================================================================
//
//       Filename:  5719.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/02/2016 17:08:18
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string.h>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};
const int MAX_N = 555;

int N, M, S, D, Dis[MAX_N];
vector<pi> V[MAX_N], RV[MAX_N];
int Chk[MAX_N][MAX_N];

void Find(int v)
{
	for(pi line : RV[v])
		if(Dis[line.fi] + line.se == Dis[v])
		{
			Find(line.fi);
			Chk[line.fi][v] = 1;
		}
}
void getDis()
{
	for(int i=0; i<N; i++) Dis[i] = INF;
	priority_queue<pi> Q;
	Q.push(mp(-0, S)); Dis[S] = 0;
	while(!Q.empty())
	{
		pi now = Q.top(); Q.pop();
		if(Dis[now.se] < -now.fi) continue;
		for(pi line : V[now.se])
			if(Dis[line.fi] > line.se - now.fi && Chk[now.se][line.fi] == 0)
				Q.push(mp(-(Dis[line.fi] = line.se - now.fi), line.fi));
	}
}

int main() {
	while(1)
	{
		scanf("%d%d", &N, &M);
		if(N == 0 && M == 0) break;
		scanf("%d%d", &S, &D);
		for(int i=0; i<M; i++)
		{
			int x, y, c; scanf("%d%d%d", &x, &y, &c);
			V[x].pb(mp(y, c)); RV[y].pb(mp(x, c));
		}

		getDis();
		Find(D);
		getDis();
		if(Dis[D] == INF) Dis[D] = -1;
		printf("%d\n", Dis[D]);

		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
				Chk[i][j] = 0;
			V[i].clear();
			V[i].shrink_to_fit();
			RV[i].clear();
			RV[i].shrink_to_fit();
		}
	}
	return 0;
}










