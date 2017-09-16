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
const pi Ch[4] ={ mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1) };

int N, M, K, Nr[111][111];

int main() {
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N >> M >> K;

	for(int i=0, x, y; i<K; i++)
		scanf("%d%d", &x, &y), Nr[x][y] = 1;
	
	int ans = 0;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
	{
		if(Nr[i][j] != 1) continue;
		queue<pi> Q; Q.push(mp(i, j));
		Nr[i][j] = 2;

		int cnt = 0;
		while(!Q.empty())
		{
			cnt++;
			pi now = Q.front(); Q.pop();
			for(int k=0; k<4; k++)
			{
				pi nx = now + Ch[k];
				if(Nr[nx.fi][nx.se] != 1) continue;
				Nr[nx.fi][nx.se] = 2;
				Q.push(nx);
			}
		}
		ans = max(ans, cnt);
	}

	cout << ans;
	return 0;
}