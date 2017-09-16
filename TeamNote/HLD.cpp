//https://oj.uz/problem/view/KOI16_tree

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<double, double> pd;
typedef pair<int, int> pi; typedef pair<ll, int> pli;
typedef pair<ll, ll> pll; typedef pair<ll, pi> plp;
typedef tuple<int, int, int> ti; typedef tuple<ll, int, int> tli;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 2e5 + 100, MAX_Q = 2e5 + 100, LOG_N = 21;

int N, Q, iP[MAX_N];
vector<int> Ed[MAX_N];
int P[LOG_N][MAX_N], D[MAX_N], S[MAX_N];
int predfs(int v, int p) {
	D[v] = D[p] + 1; S[v] = 1; P[0][v] = p;
	for(int w : Ed[v]) if(w != p) S[v] += predfs(w, v);
	return S[v];
}

struct BIT {
	int val[MAX_N];
	BIT() { memset(val, 0, sizeof(val)); }
	void update(int v, int k) { for(v+=10; v<MAX_N; v+=v&-v) val[v]+=k; }
	int getSum(int v) { int res=0; for(v+=10; v; v-=v&-v) res+=val[v]; return res; }
	int getSum(int a, int b) { return getSum(b) - getSum(a-1); }
}bit;
int eN = 0;
int eIx[MAX_N], fIx[MAX_N];
void makedfs(int v, int p, int h) {
	//	printf("%d %d %d\n", v, p, h);
	if(v != N/2) bit.update(eN, 1), eIx[v] = eN++; fIx[v] = h;
	int ix = -1;
	for(int w : Ed[v]) if(w != p && (ix == -1 || S[ix] < S[w])) ix = w;
	if(ix == -1) return;
	makedfs(ix, v, h);
	for(int w : Ed[v]) if(w != p && w != ix) makedfs(w, v, w);
}
int getL(int a, int b) {
	if(D[a] > D[b]) swap(a, b);
	for(int p=LOG_N-1; p>=0; p--) if((D[b]-D[a])&(1<<p)) b=P[p][b];
	if(a == b) return a;
	for(int p=LOG_N-1; p>=0; p--) if(P[p][a]!=P[p][b]) a=P[p][a], b=P[p][b];
	return P[0][a];
}
bool isCan(int fr, int to) {
	int hd = fIx[fr];
	if(D[to] < D[hd]) {
		int val = bit.getSum(eIx[hd], eIx[fr]);
		if(val != D[fr] - D[hd] + 1) return false;
		return isCan(P[0][hd], to);
	} else {
		int val = bit.getSum(eIx[fr] - (D[fr] - D[to]) + 1, eIx[fr]);
		return val == (D[fr] - D[to]);
	}
	printf("what?\n");
	return false;
}
int main() {
	cin >> N >> Q;
	for(int i=2; i<=N; i++) scanf("%d", &iP[i]);
	for(int i=2; i<=N; i++) Ed[i].push_back(iP[i]), Ed[iP[i]].push_back(i);
	predfs(N/2, 0);
	for(int p=1; p<LOG_N; p++) for(int i=1; i<=N; i++) P[p][i] = P[p-1][P[p-1][i]];
	makedfs(N/2, 0, N/2);
	for(int q=1; q<=Q; q++) {
		int b, c, d; scanf("%d%d%d", &b, &c, &d);
		int l = getL(b, c);
		//		printf("[%d %d -> %d]\n", b, c, l);
		//		printf("b %d | c %d\n", isCan(b, l), isCan(c, l));
		bool ans = (isCan(b, l) & isCan(c, l));
		puts(ans?"YES":"NO");
		if(d == 1) {
			int x = b, y = iP[b];
			if(!ans) x = c, y = iP[c];
			if(x == 1)
				if(D[x] > D[y]) swap(x, y);
			if(bit.getSum(eIx[y], eIx[y]) == 0) continue;
			bit.update(eIx[y], -1);
		}
	}
	return 0;
}