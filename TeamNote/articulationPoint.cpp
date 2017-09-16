#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<double, double> pd;
typedef pair<int, int> pi; typedef pair<ll, int> pli;
typedef pair<ll, ll> pll; typedef pair<ll, pi> plp;
typedef tuple<int, int, int> ti; typedef tuple<ll, int, int> tli;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 1e5 + 100;

int N, Q;
vector<pi> Ed[MAX_N];
int IN, Ix[MAX_N], Lo[MAX_N];
int vA[MAX_N], eA[MAX_N];
void dfs(int v, int p) {
	Ix[v] = Lo[v] = ++IN;
	for(pi &e : Ed[v]) {
		int w, ix; tie(w, ix) = e;
		if(w == p) continue;
		if(Ix[w] == 0) {
			dfs(w, v);
			Lo[v] = min(Lo[v], Lo[w]);
			if(Lo[w] >= Ix[v] && v != 1) vA[v] = true;
			if(Lo[w] >  Ix[v]) eA[ix] = true;
		} else if(Ix[w] < Ix[v]) {
			Lo[v] = min(Lo[v], Ix[w]);
		}
	}
}
int main() {
	cin >> N;
	for(int i=1; i<N; i++) {
		int x, y; scanf("%d%d", &x, &y);
		Ed[x].push_back(pi(y, i)); Ed[y].push_back(pi(x, i));
	}
	dfs(1, 0);
	if(SZ(Ed[1]) >= 2) vA[1] = true;
	cin >> Q;
	for(int q=0; q<Q; q++) {
		int t, v; scanf("%d%d", &t, &v);
		bool val = (t==1 ? vA[v] : eA[v]);
		puts(val ? "yes" : "no");
	}
	return 0;
}