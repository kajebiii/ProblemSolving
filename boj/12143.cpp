#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <queue>
#include <map>
#include <string>

using namespace std;

const int MAX_N = 2e2 + 10, MAX_V = 8e3 + 100, INF = 0x3f2f1f0f;

struct ED {
	int to, fl, re;
	ED() {}
	ED(int t, int f, int r) : to(t), fl(f), re(r) {}
};

int N, WN, St, En;
vector<int> S[MAX_N];
vector<ED> Ed[MAX_V];
void addEdge(int fr, int to, int fl) {
	Ed[fr].emplace_back(to, fl, Ed[to].size());
	Ed[to].emplace_back(fr,  0, Ed[fr].size()-1);
}

int Lv[MAX_V], Ix[MAX_V];
bool bfs() {
	for(int i=St; i<=En; i++) Lv[i] = INF;
	queue<int> Q; Q.push(St); Lv[St] = 0;
	while(!Q.empty()) {
		int v = Q.front(); Q.pop();
		for(ED &e : Ed[v]) {
			int w = e.to, f = e.fl;
			if(f > 0 && Lv[w] == INF)
				Lv[w] = Lv[v] + 1, Q.push(w);
		}
	}
	return Lv[En] != INF;
}
int dfs(int v, int fl) {
	if(v == En) return fl;
	for(int &i = Ix[v]; i<Ed[v].size(); i++) {
		ED &e = Ed[v][i];
		int w = e.to, f = e.fl, r = e.re, nfl = -1;
		if(f > 0 && Lv[v] < Lv[w] && (nfl = dfs(w, min(fl, f))) > 0) {
			e.fl -= nfl;
			Ed[w][r].fl += nfl;
			return nfl;
		}
	}
	return 0;
}

const int fre = 0;
int main() {
	if(fre) freopen("input.txt", "r", stdin);
	if(fre) freopen("output.txt", "w", stdout);

	int TC; scanf("%d", &TC);
	for(int tc=1; tc<=TC; tc++) {
		scanf("%d\n", &N);
		map<string, int> Mp;
		for(int i=0; i<N; i++) {
			char sen[15000], *pos = sen; int val;
			fgets(sen, 15000, stdin);
			char word[22];
			while(sscanf(pos, "%s%n", word, &val) == 1) {
				if(Mp.count(word) == 0) Mp[word] = ++WN;
				int now = Mp[word];
				S[i].push_back(now);
				pos += val;
			}
		}

		St = 0; En = WN * 2 + 2;
		for(int e : S[0]) addEdge(St, e*2+0, INF);
		for(int f : S[1]) addEdge(f*2+1, En, INF);
		for(int w=1; w<=WN; w++) addEdge(w*2+0, w*2+1, 1);
		for(int i=2; i<N; i++) for(int w0 : S[i]) for(int w1 : S[i]) if(w0 != w1)
			addEdge(w0*2+1, w1*2+0, INF);

		int flow = 0;
		while(bfs()) {
			int nowF = 0;
			for(int i=St; i<=En; i++) Ix[i] = 0;
			for(int f=0; (f=dfs(St, INF)) > 0; nowF += f);
			flow += nowF;
		}

		printf("Case #%d: ", tc);
		printf("%d\n", flow);
		for(int i=0; i<N; i++) S[i].clear(), S[i].shrink_to_fit();
		for(int i=St; i<=En; i++) Ed[i].clear(), Ed[i].shrink_to_fit();
		WN = 0; Mp.clear();
	}
	return 0;
}