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
const pi Ch[4] ={ mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1) };

const int MAX_N = 1e2 + 10;

int N, Nr[MAX_N][MAX_N], Chk[MAX_N][MAX_N];

int main() {
	if(debug) freopen("input.txt", "r", stdin);

	cin >> N;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) scanf("%d", &Nr[i][j]);
	for(int i=1; i<=N; i++)
		Nr[i][0] = Nr[0][i] = -INF,
		Nr[i][N+1] = Nr[N+1][i] = -INF;

	int f = Nr[1][1];
	int ans = INF;
	for(int right = f; right <= 200; right++)
	{
		int l = -3, r = f, m;
		int chk = 0;
		while(l < r)
		{
			m = (l+r + 1) >> 1;
			queue<pi> Q;
			Q.push(mp(1, 1));
			Chk[1][1] = ++chk;

			while(!Q.empty())
			{
				pi now = Q.front(); Q.pop();
				for(int k=0; k<4; k++)
				{
					pi n = now + Ch[k];
					if(Nr[n.fi][n.se] < m || Nr[n.fi][n.se] > right) continue;
					if(Chk[n.fi][n.se] == chk) continue;
					Chk[n.fi][n.se] = chk;
					Q.push(n);
				}
			}
			if(Chk[N][N] == chk) l = m;
			else r = m - 1;
		}
		if(l != -3)
			ans = min(ans, right - l);
	}
	cout << ans;
	return 0;
}