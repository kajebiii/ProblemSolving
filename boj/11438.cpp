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

const int MAX_N = 1e5 + 100;

int N, M;
int Pa[21][MAX_N], Lv[MAX_N];
vector<int> Ed[MAX_N];

void DFS(int v, int p) { Pa[0][v] = p; Lv[v] = Lv[p] + 1; for(int w : Ed[v]) if(w != p) DFS(w, v); }
int getLCA(int a, int b)
{
	if(Lv[a] < Lv[b]) swap(a, b);
	for(int p=20; p>=0; p--) if((1<<p) & (Lv[a] - Lv[b])) a = Pa[p][a];
	if(a == b) return a;
	for(int p=20; p>=0; p--) if(Pa[p][a] != Pa[p][b]) a = Pa[p][a], b = Pa[p][b];
	return Pa[0][a];
}
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	cin >> N;
	for(int i=1; i<N; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		Ed[x].pb(y); Ed[y].pb(x);
	}
	
	DFS(1, 0);
	for(int p=1; p<=20; p++) for(int i=1; i<=N; i++)
		Pa[p][i] = Pa[p-1][Pa[p-1][i]];

	cin >> M;
	for(int i=0; i<M; i++)
	{
		int a, b; scanf("%d%d", &a, &b);
		printf("%d\n", getLCA(a, b));
	}

	return 0;
}