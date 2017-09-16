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

const int MAX_N = 1e3 + 50;

struct ED
{
	int x, y, c;
	ED() :x(0), y(0), c(0) {}
	ED(int X, int Y, int C) :x(X), y(Y), c(C) {}
	const bool operator<(const ED &o) const
	{
		return c < o.c;
	}
}E[MAX_N*MAX_N/2];
vector<int> V[MAX_N];
int UNF[MAX_N], N;
int F(int v) { return UNF[v] == v?v : UNF[v] = F(UNF[v]); }
void U(int a, int b) {UNF[F(a)] = F(b);}

int main() {
	if(debug) freopen("input.txt", "r", stdin);

	cin >> N;
	int EN = 0;
	for(int i=1; i<=N; i++) for(int j=i+1; j<=N; j++)
	{
		int c; scanf("%d", &c);
		E[EN++] = ED(i, j, c);
	}
	sort(E, E+EN);
	for(int i=1; i<=N; i++) UNF[i] = i;
	for(int i=0; i<EN; i++)
	{
		int x = E[i].x, y = E[i].y;
		if(F(x) == F(y)) continue;
		V[x].pb(y);
		V[y].pb(x);
		U(x, y);
	}
	for(int i=1; i<=N; i++) sort(V[i].begin(), V[i].end());
	for(int i=1; i<=N; i++)
	{
		printf("%d", (int)V[i].size());
		for(int x : V[i]) printf(" %d", x); puts("");
	}
	return 0;
}