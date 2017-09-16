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
const pi Ch[4] ={ mp(0, -1), mp(-1, 0), mp(0, 1), mp(1, 0) };

int N, M;
int Nr[55][55], Chk[55][55];
int Grp[5555];

int main() {
	if(debug) freopen("input.txt", "r", stdin);
	scanf("%d%d", &M, &N);
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) scanf("%d", &Nr[i][j]);

	int cnt = 0;
	for(int i=0; i<N; i++) for(int j=0; j<M; j++)
	{
		if(Chk[i][j] != 0) continue;
		queue<pi> Q;
		Q.push(mp(i, j));
		Chk[i][j] = ++cnt;
		while(!Q.empty())
		{
			pi now = Q.front(); Q.pop();
			Grp[Chk[now.fi][now.se]]++;
			for(int k=0; k<4; k++)
			{
				if(Nr[now.fi][now.se] & (1 << k)) continue;
				pi next = now + Ch[k];
				if(next.fi < 0 || next.se < 0 || next.fi >= N || next.se >= M) continue;
				if(Chk[next.fi][next.se] != 0) continue;
				Chk[next.fi][next.se] = cnt;
				Q.push(next);
			}
		}
	}
	printf("%d\n", cnt);
	int maxV = 0;
	for(int i=1; i<=cnt; i++) maxV = max(maxV, Grp[i]);
	printf("%d\n", maxV);

	int sumV = 0;
	for(int i=0; i<N; i++) for(int j=0; j<M; j++)
	{
		for(int k=0; k<4; k++)
		{
			pi x = mp(i, j) + Ch[k];
			if(x.fi < 0 || x.se < 0 || x.fi >= N || x.se >= M) continue;
			if(Chk[i][j] == Chk[x.fi][x.se]) continue;
			sumV = max(sumV, Grp[Chk[i][j]] + Grp[Chk[x.fi][x.se]]);
		}
	}
	printf("%d\n", sumV);
	return 0;
}


