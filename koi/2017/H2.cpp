#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, int> pli; typedef pair<ll, pi> plp;
typedef tuple<int, int, int> ti; typedef tuple<ll, int, int> tli;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 2e3 + 100, MAX_K = 1e5 + 100;

int N, K, UNF[MAX_K], Vis[MAX_N * MAX_N], Mp[MAX_N * MAX_N];
int F(int v) { return UNF[v] == v ? v : UNF[v] = F(UNF[v]); }
int U(int a, int b) {
	a = F(a); b = F(b);
	UNF[a] = b;
	return a != b;
}
int main() {
	cin >> N >> K;
	for(int i=1; i<=K; i++) UNF[i] = i;
	for(int i=0; i<N*N; i++) Vis[i] = INF;
	vector<pi> nr;
	for(int i=1; i<=K; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--; y--;
		nr.push_back(pi(x, y));
	}
	sort(ALL(nr));
	queue<pi> Q;
	for(int i=0; i<K; i++) {
		int x, y; tie(x, y) = nr[i];
		Q.push(pi(x, y));
		Vis[x*N+y] = 1;
		Mp[x*N+y] = i+1;
	}
	int cnt = K;
	for(int q=1; ; q++) {
		while(!Q.empty()) {
			int x, y; tie(x, y) = Q.front();
			int p = x*N+y;
//			printf("%d %d\n", x, y);
			if(Vis[p] != q) break; Q.pop();
			for(int k=0; k<4; k++) {
				int nx = x + "1012"[k] - '1', ny = y + "0121"[k] - '1';
				int pp = nx * N + ny;
				if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
				if(Vis[pp] <= q) {
					cnt -= U(Mp[p], Mp[pp]);
				} else if(Vis[pp] == INF) {
					Vis[pp] = q+1;
					Mp[pp] = Mp[p];
					Q.push(pi(nx, ny));
				}
			}
		}
		if(cnt == 1) {
			printf("%d\n", q-1);
			return 0;
		}
	}
	return 0;
}
