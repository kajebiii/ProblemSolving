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

const int MAX_N = 2e4 + 100;

int N, M;
vector<int> V[MAX_N];
void addEdge(int x, int y) {V[x+N].pb(y+N);}

int Ix[MAX_N], IxCnt, Gp[MAX_N], GN;
stack<int> S;
int dfs(int v)
{
	int low; S.push(v);
	low = Ix[v] = ++IxCnt;
	for(int w : V[v])
		if(Ix[w] == 0)
			low = min(low, dfs(w));
		else if(Gp[w] == 0)
			low = min(low, Ix[w]);

	if(low == Ix[v])
		for(int now = -1, G=++GN; now != v; Gp[now=S.top()] = G, S.pop());
	return low;
}
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for(int i=0; i<M; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		addEdge(-x, y);
		addEdge(-y, x);
	}
	for(int i=0; i<=2*N; i++)
		if(Ix[i] == 0) dfs(i);

	for(int i=1; i<=N; i++)
		if(Gp[i+N] == Gp[N-i])
		{
			puts("0");
			return 0;
		}
	puts("1");
	for(int i=1; i<=N; i++)
		printf("%d ", Gp[N+i] < Gp[N-i]);
	return 0;
}