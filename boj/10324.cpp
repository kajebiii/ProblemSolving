#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <functional>

using namespace std;

const int MAX_N = 1e4 + 100;
typedef pair<int, int> pi;

int N, M, K, Deg[MAX_N], Dep[MAX_N], From[MAX_N]; bool Chk[MAX_N];
vector<int> Ed[MAX_N];

const int debug = 0, fre = 0;
int main() {
	if(fre) {freopen("input.txt", "r", stdin);}
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d%d%d", &N, &M, &K);
		for(int i=0, x, y; i<M; i++) {
			scanf("%d%d", &x, &y), Ed[x].push_back(y), Ed[y].push_back(x);
			Deg[x]++; Deg[y]++;
		}
		queue<int> dQ;
		for(int i=1; i<=N; i++) if(Deg[i] == 1) {
			dQ.push(i); Dep[i] = 1; From[i] = 0;
		}
		while(!dQ.empty()) {
			int v = dQ.front(); dQ.pop();
			if(debug) printf("[%d | d %d | f %d]\n", v, Dep[v], From[v]);
			for(int w : Ed[v]) {
				Deg[w]--; Deg[v]--;
				if(Deg[w] == 1) {
					dQ.push(w);
					if(Dep[w] < Dep[v] + 1) {
						Dep[w] = Dep[v] + 1;
						From[w] = v;
					}
				}
			}
		}
		priority_queue<pi> Q;
		int ans = 0;
		for(int i=1; i<=N; i++) if(Dep[i] != 0) Q.push(make_pair(Dep[i], i)), ans++;

		function<void(int)> doChk = [&](int v) {
			if(v == 0) return;
			Chk[v] = true;
			doChk(From[v]);
		};

		while(!Q.empty() && K > 0) {
			int d, v; tie(d, v) = Q.top(); Q.pop();
			if(Chk[v]) continue;
			doChk(v);
			ans -= d; K--;
		}
		printf("%d\n", ans);

		//
		for(int i=1; i<=N; i++) Ed[i].clear(), Ed[i].shrink_to_fit();
		for(int i=1; i<=N; i++) Deg[i] = Dep[i] = From[i] = Chk[i] = 0;
	}
	return 0;
}