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

const int MAX_N = 99;

struct ED
{
	int to, capa, ix;
	ED(int T, int C, int I) :to(T), capa(C), ix(I) {}
};
vector<ED> V[MAX_N];
void add(int from, int to, int capa)
{
	V[from].pb(ED(to, capa, V[to].size()));
	V[to].pb(ED(from, capa, V[from].size()-1));
}
int N;
int ToInt(char x)
{
	if(x <= 'Z') return x - 'A';
	return x - 'a' + 'Z' - 'A' + 1;
}
int S = ToInt('A'), E = ToInt('Z');
int St[MAX_N], Lv[MAX_N];

bool bfs()
{
	for(int i=ToInt('A'); i<=ToInt('z'); i++) Lv[i] = 0;
	queue<int> Q; Q.push(S); Lv[S] = 1;
	while(!Q.empty())
	{
		int v = Q.front(); Q.pop();
		for(auto &e : V[v])
			if(e.capa != 0 && Lv[e.to] == 0)
			{
				Q.push(e.to); 
				Lv[e.to] = Lv[v] + 1;
			}
	}
	if(Lv[E] == 0) return false;
	return true;
}

int dfs(int v, int f)
{
	if(v == E) return f;
	for(int &i = St[v]; i<V[v].size(); i++)
	{
		auto &e = V[v][i];
		int m = -1;
		if(Lv[e.to] > Lv[v] && e.capa != 0 && (m = dfs(e.to, min(f, e.capa))) > 0)
		{
			e.capa -= m;
			V[e.to][e.ix].capa += m;
			return m;
		}
	}
	return 0;
}

int main() {
	if(debug) freopen("input.txt", "r", stdin);

	scanf("%d\n", &N);
	for(int i=0; i<N; i++)
	{
		char x, y; int c;
		scanf("%c %c %d\n", &x, &y, &c);
		int a = ToInt(x), b = ToInt(y);
		add(a, b, c);
	}

	int ans = 0;
	while(true)
	{
		if(!bfs()) break;
		int f;
		for(int i=ToInt('A'); i<=ToInt('z'); i++) St[i] = 0;
		while((f = dfs(S, INF)) != 0)
			ans += f;
	}

	cout << ans;
	return 0;
}