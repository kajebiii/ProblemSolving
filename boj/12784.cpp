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
const int MAX_N = 1e3 + 10;

int N, M;
vector<pi> V[MAX_N];
int getDy(int v, int p)
{
	int result = 0, cnt = 0;
	for(pi &l : V[v])
	{
		int w, c; tie(w, c) = l;
		if(w != p)
		{
			result += min(getDy(w, v), c);
			cnt++;
		}
	}
	if(cnt == 0) return INF;
	return result;
}
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	int T; cin >> T;
	while(T--)
	{
		scanf("%d%d", &N, &M);
		for(int i=0; i<M; i++)
		{
			int x, y, c; scanf("%d%d%d", &x, &y, &c);
			V[x].pb(mp(y, c)); V[y].pb(mp(x, c));
		}
		if(M == 0) printf("0\n");
		else printf("%d\n", getDy(1, 0));
		for(int i=1; i<=N; i++) { V[i].clear(); V[i].shrink_to_fit(); }
	}
	return 0;
}