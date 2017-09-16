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

int N, M, Nr[555][555];

int main() {
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) scanf("%d", &Nr[i][j]);
	int nr = 0, ans = 0;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
	{
		if(Nr[i][j] == 0) continue;
		int cnt = 0;
		nr++;
		queue<pi> Q; Q.push(mp(i, j));
		Nr[i][j] = 0;
		while(!Q.empty())
		{
			pi now = Q.front(); Q.pop();
			cnt++;
			for(int k=0; k<4; k++)
			{
				pi n = now + Ch[k];
				if(Nr[n.fi][n.se] == 0) continue;
				Nr[n.fi][n.se] = 0;
				Q.push(n);
			}
		}
		ans = max(ans, cnt);
	}
	cout << nr << endl << ans;
	return 0;
}