#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, int> pli;
typedef pair<ll, ll> pll; typedef pair<ll, pi> plp;
typedef tuple<int, int, int> ti; typedef tuple<ll, int, int> tli;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 3e5 + 100;

int N, M;
vector<int> Ed[MAX_N];
int main() {
	cin >> N >> M;
	for(int i=0; i<M; i++) {
		int x, y; scanf("%d%d", &x, &y); x--; y--;
		Ed[x].push_back(y); Ed[y].push_back(x);
	}
	if(N == M) {
		queue<int> Q;
		vector<int> d(N, 0);
		vector<bool> vis(N, false);
		for(int i=0; i<N; i++) d[i] = SZ(Ed[i]);
		for(int i=0; i<N; i++) if(d[i] == 1) Q.push(i), vis[i] = true;
		while(!Q.empty()) {
			int v = Q.front(); Q.pop();
			for(int w : Ed[v]) if(!vis[w]) {
				d[v]--; d[w]--;
				if(d[w] == 1) Q.push(w), vis[w] = true;
			}
		}
		ll ans = 0;
		for(int i=0; i<N; i++) if(vis[i] == false) ans += (i+1);
		printf("%lld\n", ans);
		return 0;
	}


	vector<pi> deg;
	for(int i=0; i<N; i++) deg.push_back(pi((int)SZ(Ed[i]), i));
	sort(ALL(deg)); reverse(ALL(deg));

	ll ans = 0;
	for(int k=0; k<min(5, N); k++) {
		int st = deg[k].two;
		vector<bool> vis(N, false);
		vis[st] = true;

		bool isPos = true;
		for(int i=0; i<N; i++) {
			if(vis[i]) continue;
			int vcnt = 0, ecnt = 0;
			queue<int> Q; Q.push(i); vis[i] = true;
			while(!Q.empty()) {
				int v = Q.front(); Q.pop();
				vcnt++;
				for(int w : Ed[v]) {
					if(w != st) ecnt++;
					if(!vis[w]) vis[w] = true, Q.push(w);
				}
			}
//			printf("[%d %d]\n", vcnt, ecnt);
			if(vcnt <= ecnt/2) {
				isPos = false;
				break;
			}
		}
		if(isPos) {
			ans += (st+1);
//			printf("%d\n", st);
		}
	}
	printf("%lld\n", ans);
	return 0;
}