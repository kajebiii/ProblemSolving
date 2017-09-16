#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int MAX_N = 2e2 + 10, INF = 0x7fffffff;

int N, Nr[MAX_N][3];
vector<int> Ed[MAX_N];

int Ix[MAX_N], IN, Gp[MAX_N], GN, GCnt[MAX_N]; 
stack<int> S;
vector<int> Gl[MAX_N];
int getLow(int v) {
	int low = ++IN; Ix[v] = IN; S.push(v);
	for(int w : Ed[v])
		if(Ix[w] == 0) low = min(low, getLow(w));
		else if(Gp[w] == 0) low = min(low, Ix[w]);
	if(Ix[v] == low)
		for(GN++; 1;) {
			int t = S.top(); S.pop();
			Gp[t] = GN; GCnt[GN]++; Gl[GN].push_back(t);
			if(t == v) break;
		}
	return low;
}

const int fre = 0;
int main() {
	if(fre) freopen("moocast.in", "r", stdin);
	if(fre) freopen("moocast.out", "w", stdout);

	scanf("%d", &N);
	for(int i=0; i<N; i++) for(int j=0; j<3; j++) scanf("%d", &Nr[i][j]);
	auto canTransmit = [&](int a, int b) { // a -> b
		int dx = Nr[a][0] - Nr[b][0], dy = Nr[a][1] - Nr[b][1];
		return dx * dx + dy * dy <= Nr[a][2] * Nr[a][2];
	};
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) if(i != j && canTransmit(i, j)) Ed[i].push_back(j);
	
	auto bfs = [&](int s) {
		vector<bool> vis = vector<bool>(N+1, false);
		queue<int> Q; Q.push(s); vis[s] = true;
		int cnt = 0;
		while(!Q.empty()) {
			int v = Q.front(); Q.pop();
			cnt++;
			for(int w : Ed[v]) if(vis[w] == false)
				vis[w] = true, Q.push(w);
		}
		return cnt;
	};
	int ans = 0;
	for(int i=0; i<N; i++) ans = max(ans, bfs(i));
	/*
	for(int i=0; i<N; i++) if(Ix[i] == 0) getLow(i);

	int ans = 0;
	for(int g=1; g<=GN; g++) {
		int maxV = 0;
		vector<bool> Chk = vector<bool>(GN+1, false);
		for(int v : Gl[g]) for(int w : Ed[v]) if(g != Gp[w]) Chk[Gp[w]] = true;
		for(int i=1; i<=GN; i++) if(Chk[i]) GCnt[g] += GCnt[i];
		ans = max(ans, GCnt[g]);
	}
	*/
	printf("%d\n", ans);
	return 0;
}