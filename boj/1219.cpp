#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)((v).size()))
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 1e2 + 10;
int N, St, En, M;
vector<pi> Ed[MAX_N];
vector<int> REd[MAX_N];
bool FromEn[MAX_N];
int Money[MAX_N];

int main() {
	cin >> N >> St >> En >> M;
	for(int i=0; i<M; i++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		Ed[a].push_back(pi(b, c));
		REd[b].push_back(a);
	}
	queue<int> Q; Q.push(En); FromEn[En] = true;
	while(!Q.empty()) {
		int v = Q.front(); Q.pop();
		for(int w : REd[v]) if(!FromEn[w])
			FromEn[w] = true, Q.push(w);
	}
	for(int i=0; i<N; i++) scanf("%d", &Money[i]);

	vector<bool> vis(N, false);
	vector<ll> dis(N, -LINF);
	vis[St] = true; dis[St] = Money[St];
	bool last = false;
	for(int p=1; p<=N; p++) {
		bool changed = false;
		for(int v=0; v<N; v++) for(pi &e : Ed[v]) {
			int w, c; tie(w, c) = e;
			if(vis[v] && dis[w] < dis[v] - c + Money[w]) {
				vis[w] = true, dis[w] = dis[v] - c + Money[w], changed = true;
				if(p == N && FromEn[w] == true) {
					puts("Gee");
					return 0;
				}
			}
		}
		if(p == N && changed) last = true;
	}
	if(vis[En] == false) puts("gg");
	else printf("%lld\n", dis[En]);
	return 0;
}


