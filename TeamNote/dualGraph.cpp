//https://www.acmicpc.net/problem/13145

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 5e4 + 100, MAX_M  = 6 * MAX_N, MAX_NR = 1e6 + 100;

int sign(ll x) { return (x>0) - (x<0); }
struct PT {
	int x, y, p;
	PT() {}
	PT(int xx, int yy) : x(xx), y(yy), p(y < 0 || y == 0 && x < 0) {}
	PT operator-(const PT &o) const { return PT(x-o.x, y-o.y); }
	ll cross(const PT &o) const { return 1ll*x*o.y - 1ll*y*o.x; }
	int ccw(const PT &o) const { return sign(cross(o)); }
	int ccw(const PT &a, const PT &b) const { return (b-*this).ccw(b-*this); }
	bool operator<(const PT &o) const {
		if(p != o.p) return p < o.p;
		return ccw(o) > 0;
	}
};

struct ED {
	int w, c, i;
	ED() {}
	ED(int ww, int cc, int ii) : w(ww), c(cc), i(ii) {}
};


int N, M;
vector<PT> Ps;
vector<ED> Ed[MAX_N];
vector<ED> rEd[MAX_M]; int eN;
typedef pair<PT, int> ppti;
void add(int x, int y, int c) {
	Ed[x].push_back(ED(y, c, eN++));
	Ed[y].push_back(ED(x, c, eN++));
}
int St, En, Up, Dn;
map<int, int> Ix[MAX_N];
struct UF {
	int UNF[MAX_M];
	UF() {}
	void clear() { for(int i=0; i<MAX_M; i++) UNF[i] = i; }
	int F(int v) { return UNF[v] == v ? v : UNF[v] = F(UNF[v]); }
	void U(int a, int b) { a = F(a), b = F(b); UNF[a] = b; }
}uf;
void makeGraph() {
	{ // init make up and down node
		St = 0; En = N-1, Up = N, Dn = N+2;
		Ps.push_back(PT(0, MAX_NR));
		add(St, SZ(Ps)-1, INF);
		Ps.push_back(PT(MAX_NR, MAX_NR));
		add(En, SZ(Ps)-1, INF);
		add(SZ(Ps)-2, SZ(Ps)-1, INF);

		Ps.push_back(PT(0, -MAX_NR));
		add(St, SZ(Ps)-1, INF);
		Ps.push_back(PT(MAX_NR, -MAX_NR));
		add(En, SZ(Ps)-1, INF);
		add(SZ(Ps)-2, SZ(Ps)-1, INF);

		N = SZ(Ps);
	}

	for(int v=0; v<N; v++) {
		sort(ALL(Ed[v]), [&](ED pa, ED pb) {
			int a = pa.w, b = pb.w;
			return Ps[a] - Ps[v] < Ps[b] - Ps[v];
		});
		for(int i=0; i<SZ(Ed[v]); i++) Ix[v][Ed[v][i].w] = i;
	}

	uf.clear();
	for(int v=0; v<N; v++) for(int i=0; i<SZ(Ed[v]); i++) {
		int ix = Ed[v][i].i;
		ED &e = Ed[v][(i+1)%SZ(Ed[v])];
		int w = e.w, rix = Ed[w][Ix[w][v]].i;
		uf.U(ix, rix);
	}

	for(int v=0; v<N; v++) for(ED &e : Ed[v]) {
		int w = e.w, c = e.c;
		int a = uf.F(e.i), b = uf.F(Ed[w][Ix[w][v]].i);
		if(b < a) continue;
		rEd[a].push_back(ED(b, c, -1));
		rEd[b].push_back(ED(a, c, -1));

		//		printf("%d %d %d (%d %d)\n", v, w, c, a, b);
	}

}

vector<int> dijk(int n, vector<ED> ed[], int s) {
	priority_queue<pi, vector<pi>, greater<pi>> Q;
	vector<int> dis(n, INF), vis(n, 0);
	Q.push(pi(0, s)); dis[s] = 0;
	while(!Q.empty()) {
		int d, v; tie(d, v) = Q.top(); Q.pop();
		if(vis[v]) continue; vis[v] = true;
		for(ED &e : ed[v]) {
			int w = e.w, c = e.c;
			if(dis[w] > dis[v] + c) Q.push(pi(dis[w] = dis[v] + c, w));
		}
	}
	return dis;
}
int allC = 0;
void subtask2() {
	makeGraph();
	//	printf("[%d | %d]\n", Ed[Up][1].w, Ed[Dn][0].w);
	int s = uf.F(Ed[Up][1].i), e = uf.F(Ed[Dn][0].i);
	//	printf("%d %d\n", s, e);
	vector<int> sDis = dijk(eN, rEd, s), eDis = dijk(eN, rEd, e);
	int ans = INF;
	for(int v=0; v<eN; v++) for(ED &e : rEd[v]) {
		//		printf("[%d %d] (%d + %d)\n", v, e.w, sDis[v], eDis[e.w]);
		ans = min(ans, sDis[v] + eDis[e.w]);
	}
	printf("%d\n", allC - ans);
}
void subtask1() {
	vector<int> dis = dijk(N, Ed, 0);
	printf("%d ", dis[N-1]);
}
int main() {
	cin >> N;
	for(int i=0; i<N; i++) { int x, y; scanf("%d%d", &x, &y); Ps.push_back(PT(x, y)); }
	cin >> M;
	for(int i=0; i<M; i++) {
		int x, y, c; scanf("%d%d%d", &x, &y, &c); x--; y--;
		add(x, y, c); allC += c;
	}
	//	printf("%d\n", allC);
	subtask1();
	subtask2();
	return 0;
}