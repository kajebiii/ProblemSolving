
const int MAX_N = 4e2 + 50;

struct ED{
	int to, fl, re;
	ED(int t, int f, int r) : to(t), fl(f), re(r) {}
};
vector<ED> Ed[MAX_N];
void add(int fr, int to, int fl) {
	Ed[fr].emplace_back(to, fl, SZ(Ed[to]));
	Ed[to].emplace_back(fr,  0, SZ(Ed[fr])-1);
}

int St, En, Lv[MAX_N], Ix[MAX_N];
bool bfs() {
	for(int i=St; i<=En; i++) Lv[i] = INF;
	queue<int> Q; Q.emplace(St); Lv[St] = 0;
	while(!Q.empty()) {
		int v = Q.front(); Q.pop();
		for(ED &val : Ed[v]) {
			int w = val.to, f = val.fl, r = val.re;
			if(f > 0 && Lv[w] == INF) {
				Lv[w] = Lv[v] + 1;
				Q.emplace(w);
			}
		}
	}
	return Lv[En] != INF;
}
void initDfs() {
	for(int i=St; i<=En; i++) Ix[i] = 0;
}
int dfs(int v, int mf) {
	if(v == En) return mf;
	for(int &i = Ix[v]; i < SZ(Ed[v]); i++) {
		ED &val = Ed[v][i];
		int w = val.to, f = val.fl, r = val.re;
		int nf;
		if(Lv[w] == Lv[v] + 1 && f > 0 && (nf = dfs(w, min(f, mf))) > 0) {
			val.fl -= nf;
			Ed[w][r].fl += nf;
			return nf;
		}
	}
	return 0;
}
