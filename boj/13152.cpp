#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long ll;
typedef pair<int, int> pi;

const int MAX_N = 5e2 + 10, MAX_V = MAX_N * 3, INF = 0x3f2f1f0f;

struct ED {
	int to, fl, re;
	ED() {}
	ED(int t_, int f_, int r_) : to(t_), fl(f_), re(r_) {}
};
vector<ED> Ed[MAX_V], Memo[MAX_V];
void addEdge(int fr, int to, int fl) {
	Ed[fr].emplace_back(to, fl, Ed[to].size());
	Ed[to].emplace_back(fr,  0, Ed[fr].size()-1);
}
int St, En, N, M;

int Lv[MAX_V], Ix[MAX_V];
bool bfs() {
	for(int i=St; i<=En; i++) Lv[i] = -1;
	queue<int> Q; Q.push(St); Lv[St] = 0;
	while(!Q.empty()) {
		int v = Q.front(); Q.pop();
		for(ED &e : Ed[v]) {
			if(Lv[e.to] == -1 && e.fl > 0)
				Q.push(e.to), Lv[e.to] = Lv[v] + 1;
		}
	}
	return Lv[En] != -1;
}
int dfs(int v, int fl) {
	if(v == En) return fl;
	for(int &i = Ix[v]; i<Ed[v].size(); i++) {
		ED &e = Ed[v][i]; int f = 0;
		if(e.fl > 0 && Lv[e.to] > Lv[v] && (f = dfs(e.to, min(e.fl, fl))) > 0) {
			e.fl -= f;
			Ed[e.to][e.re].fl += f;
			return f;
		}
	}
	return 0;
}
bool isPossible(int val) {
	for(int i=St; i<=En; i++) Ed[i] = Memo[i];
	for(int i=1; i<=N; i++) addEdge(2*N+i, En, val);

	int flow = 0;
	while(bfs()) {
		for(int i=St; i<=En; i++) Ix[i] = 0;
		for(int f; (f=dfs(St, INF)) > 0; flow += f);
	}
//	printf("val : %d [%d]\n", val, flow);
	return flow == M;
}

int inD[MAX_N];
int main() {
	scanf("%d%d", &N, &M);
	rep(i, M) {
		int a, b; scanf("%d%d", &a, &b);
		inD[a]++;
		addEdge(a, N+b, 1);
	}
	for(int i=1; i<=N; i++) addEdge(i, 2*N+i, INF), addEdge(N+i, 2*N+i, INF);
	St = 0; En = 3*N + 1;	
	for(int i=1; i<=N; i++) addEdge(St, i, inD[i]);

	for(int i=St; i<=En; i++) Memo[i] = Ed[i];

	int res = -1;
	for(int l=0, r=M; l<=r; ) {
		int m = (l+r) >> 1;
		if(isPossible(m)) res = m, r = m-1; else l = m+1;
	}
	printf("%d\n", res);
	return 0;
}