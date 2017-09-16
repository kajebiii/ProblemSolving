//kdh9949

#include "factories.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct E { int x, d; };

const ll inf = 1e18;
int n, q, c[500010], s[500010], p[500010], d[500010], bc[500010];
ll md[19][500010], bd[500010];
vector<E> e[500010];

int sf(int x, int p) {
	s[x] = 1;
	for(auto &i : e[x]) if(!c[i.x] && i.x != p) s[x] += sf(i.x, x);
	return s[x];
}

int cf(int x, int p, int t) {
	for(auto &i : e[x])
		if(!c[i.x] && i.x != p && s[i.x] > t / 2) return cf(i.x, x, t);
	return x;
}

void g(int x, int p, int d, ll v) {
	md[d][x] = v;
	for(auto &i : e[x]) if(!c[i.x] && i.x != p) g(i.x, x, d, v + i.d);
}

int f(int x, int de) {
	x = cf(x, 0, sf(x, 0));
	d[x] = de;
	c[x] = 1;
	for(auto &i : e[x]) {
		if(c[i.x]) continue;
		g(i.x, x, de, i.d);
		p[f(i.x, de + 1)] = x;
	}
	return x;
}

ll upd(int x, int g) {
	ll ret = inf;
	for(int t = x, u = d[x]; t; t = p[t], u--) {
		if(!g && (bc[t] != q || bd[t] > md[u][x])) {
			bd[t] = md[u][x];
			bc[t] = q;
		} else if(g && bc[t] == q) {
			ret = min(ret, bd[t] + md[u][x]);
		}
	}
	return ret;
}

void Init(int N, int A[], int B[], int D[]) {
	n = N;
	for(int i = 0, x, y, z; i < n - 1; i++) {
		x = A[i] + 1; y = B[i] + 1; z = D[i];
		e[x].push_back({y, z});
		e[y].push_back({x, z});
	}
	f(1, 0);
}

ll Query(int S, int X[], int T, int Y[]) {
	q++;
	for(int i = 0; i < S; i++) upd(X[i] + 1, 0);
	ll ret = inf;
	for(int i = 0; i < T; i++) ret = min(ret, upd(Y[i] + 1, 1));
	return ret;
}