#include <stdio.h>
#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
#include <map>
#include <queue>

using namespace std;

const int MAX_N = 3e3 + 100, INF = 0x7fffffff;

int M, N;
map<string, int> toNr;
vector<int> Ed[MAX_N];

int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d", &M);
		while(M--) {
			char a[99], b[99]; scanf("%s%s", a, b);
			if(toNr.count(a) == 0) toNr[a] = N++;
			if(toNr.count(b) == 0) toNr[b] = N++;
			Ed[toNr[a]].push_back(toNr[b]);
			Ed[toNr[b]].push_back(toNr[a]);
		}

		int cnt = 0;
		for(int s=0; s<N; s++) {
			vector<int> dis = vector<int>(N, INF);
			queue<int> Q; Q.push(s); dis[s] = 0;
			while(!Q.empty()) {
				int v = Q.front(); Q.pop();
				for(int w : Ed[v]) if(dis[w] == INF)
					dis[w] = dis[v] + 1, Q.push(w);
			}
			int now = -1;
			for(int i=0; i<N; i++) now = max(now, dis[i]);
			if(now > 6) cnt++;
		}

		if(cnt * 20 <= N) puts("YES"); else puts("NO");

		for(int i=0; i<N; i++) Ed[i].clear(), Ed[i].shrink_to_fit();
		toNr.clear(); N = 0;
	}
	return 0;
}