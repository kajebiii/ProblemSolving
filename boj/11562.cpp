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

int N, M, Dis[333][333];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) if(i != j) Dis[i][j] = INF;
	while(M--)
	{
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		Dis[a][b] = 0;
		Dis[b][a] = 1 - c;
	}
	for(int k=1; k<=N; k++) for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		if(Dis[i][k] != INF && Dis[k][j] != INF)
			Dis[i][j] = min(Dis[i][j], Dis[i][k] + Dis[k][j]);

	int Q; cin >> Q;
	while(Q--)
	{
		int a, b; scanf("%d%d", &a, &b);
		printf("%d\n", Dis[a][b]);
	}
	return 0;
}