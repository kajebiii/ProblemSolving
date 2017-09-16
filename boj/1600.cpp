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
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) { return mp(x.fi+y.fi, x.se+y.se); }

const int INF = 0x7fffffff;
const pi Ch[4] ={ mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};
const pi ChH[8] ={ mp(-2, -1), mp(-2, 1), mp(2, -1), mp(2, 1), mp(-1, -2), mp(-1, 2), mp(1, -2), mp(1, 2) };

int K, N, M;
int Dy[33][222][222];
int Map[222][222];
queue<tuple<int, int, int> > Q;
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	scanf("%d%d%d", &K, &M, &N);
	for(int k=0; k<=K; k++) for(int i=0; i<N; i++) for(int j=0; j<M; j++)
		Dy[k][i][j] = INF;
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) scanf("%d", &Map[i][j]);
	Q.push(make_tuple(K, 0, 0));
	Dy[K][0][0] = 0;
	
	while(!Q.empty())
	{
		int l, x, y;
		tie(l, x, y) = Q.front(); Q.pop();

		for(int k=0; k<4; k++)
		{
			pi np = mp(x, y) + Ch[k];
			if(np.fi < 0 || np.se < 0 || np.fi >= N || np.se >= M) continue;
			if(Map[np.fi][np.se] == 1) continue;
			if(Dy[l][np.fi][np.se] != INF) continue;
			Dy[l][np.fi][np.se] = Dy[l][x][y] + 1;
			Q.push(make_tuple(l, np.fi, np.se));
		}
		if(l != 0) for(int k=0; k<8; k++)
		{
			pi np = mp(x, y) + ChH[k];
			if(np.fi < 0 || np.se < 0 || np.fi >= N || np.se >= M) continue;
			if(Map[np.fi][np.se] == 1) continue;
			if(Dy[l-1][np.fi][np.se] != INF) continue;
			Dy[l-1][np.fi][np.se] = Dy[l][x][y] + 1;
			Q.push(make_tuple(l-1, np.fi, np.se));
		}
	}
	int ans = INF;
	for(int k=0; k<=K; k++) ans = min(ans, Dy[k][N-1][M-1]);
	if(ans == INF) printf("-1");
	else printf("%d", ans);
	return 0;
}