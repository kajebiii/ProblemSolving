#include <stdio.h>
#include <functional>
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
typedef tuple<int, int, int> ti;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define fi first
#define se second
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) { return mp(x.fi+y.fi, x.se+y.se); }

const int INF = 0x7fffffff;
const pi Ch[4] ={ mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1) };

const int MAX_N = 133;

int N, Nr[MAX_N][MAX_N];
int Dy[MAX_N][MAX_N];

int main() {
	if(debug) freopen("input.txt", "r", stdin);
	int T = 0;
	while(scanf("%d", &N) == 1)
	{
		if(N == 0) break;
		for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) scanf("%d", &Nr[i][j]);
		for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) Dy[i][j] = INF;
		priority_queue<ti, vector<ti>, greater<ti> > Q;
		Q.push(mt(Nr[1][1], 1, 1));
		while(!Q.empty())
		{
			int c, x, y;
			tie(c, x, y) = Q.top(); Q.pop();
			if(Dy[x][y] != INF) continue;
			Dy[x][y] = c;
			pi now = mp(x, y);
			for(int k=0; k<4; k++)
			{
				pi n = now + Ch[k];
				if(n.fi <= 0 || n.se <= 0 || n.fi > N || n.se > N) continue;
				if(Dy[n.fi][n.se] != INF) continue;
				Q.push(mt(c + Nr[n.fi][n.se], n.fi, n.se));
			}
		}
		printf("Problem %d: %d\n", ++T, Dy[N][N]);
	}
	return 0;
}