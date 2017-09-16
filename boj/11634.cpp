#include <stdio.h>
#include <algorithm>
#include <vector>
#include <tuple>
#include <map>
#include <unordered_map>

using namespace std;

const int MAX_N = 36, INF = 0x7fffffff;
typedef pair<int, int> pi;
typedef long long ll;

int N, M;
vector<pi> Ed[MAX_N], Rd[MAX_N];

int Ans = INF;
vector<int> who;
void updateAns() {
	int cnt = 0, v = 0, sum = 0;
	while(v != 0 || cnt == 0) {
		sum += Ed[v][who[v]].second;
		v = Ed[v][who[v]].first;
		cnt++;
		if(cnt > N) break;
	}
	if(cnt != N) return;
	Ans = min(Ans, sum);
}
void choose(int v, int k) {
	if(Ed[v].size() <= k) return;
	if(who[v] != -1) return;
	int w = Ed[v][k].first;
	who[v] = k;
	if(Rd[w].size() == 1) return;
	int ix = (v == Rd[w][0].first), o = Rd[w][ix].first;
	// v -> w, o -> w, o -> (not w);
	choose(o, (Ed[o][0].first == w) );
}
void calc(int v) {
	if(v == N) return updateAns();
	if(who[v] == -1) {
		vector<int> memo = who;
		choose(v, 0);
		calc(v+1);
		who = memo;

		choose(v, 1);
		calc(v+1);
		who = memo;
	}else return calc(v+1);
}

int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d%d", &N, &M);
		while(M--) {
			int a, b, c; scanf("%d%d%d", &a, &b, &c);
			Ed[a].emplace_back(b, c);
			Rd[b].emplace_back(a, c);
		}
		who = vector<int>(N, -1);
		for(int i=0; i<N; i++) if(Ed[i].size() == 1) who[i] = 0;
		Ans = INF;
		calc(0);
		printf("%d\n", Ans);
		for(int i=0; i<N; i++) Ed[i].clear(), Ed[i].shrink_to_fit(), Rd[i].clear(), Rd[i].shrink_to_fit();
	}
	return 0;
}