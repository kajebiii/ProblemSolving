#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct ED {
	int to, fl, co, re;
	ED(int t, int f, int c, int r) : to(t), fl(f), co(c), re(r) {};
};

const int MAX_N = 5e2 + 20, MAX_V = 2 * MAX_N;

int N, M;
int Co[2][MAX_N], Dis[MAX_N][MAX_N], St, En;
vector<int> E[MAX_N];
vector<ED> Ed[MAX_V];

void addEdge(int fr, int to, int fl, int co) {
	Ed[fr].emplace_back(to, fl,  co, Ed[to].size());
	Ed[to].emplace_back(fr,  0, -co, Ed[fr].size()-1);
}

void init() {
	scanf("%d%d", &N, &M);
	while(M--) {
		int x, y; scanf("%d%d", &x, &y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	for(int j=0; j<2; j++) for(int i=1; i<=N; i++)
		scanf("%d", &Co[j][i]);
	auto getDis = [&](int s) {
		vector<bool> chk = vector<bool>(N+1, false);
		queue<int> Q; Q.push(s); chk[s] = true;
		Dis[s][s] = 0;
		while(!Q.empty()) {
			int v = Q.front(); Q.pop();
			for(int w : E[v]) {
				if(chk[w] == true) continue;
				Dis[s][w] = Dis[s][v] + 1;
				chk[w] = true;
				Q.push(w);
			}
		}
	};
	for(int i=1; i<=N; i++) getDis(i);

	St = 0, En = 2*N + 1;
	for(int i=1; i<=N; i++) addEdge(St, i, 1, 0);
	for(int i=1; i<=N; i++) addEdge(i+N, En, 1, 0);
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		if(Co[0][i] == Co[1][j] && Co[0][i] == 1)
			addEdge(i, j+N, 1, Dis[i][j]);
}

int D[MAX_V], Wh[MAX_V], Ix[MAX_V]; bool inQ[MAX_V];
bool spfa() {
	for(int i=St; i<=En; i++) D[i] = 1e9, inQ[i] = false;
	queue<int> Q; Q.push(St); D[St] = 0, inQ[St] = true;
	while(!Q.empty()) {
		int v = Q.front(); Q.pop(); inQ[v] = false;
		for(int i=0; i<Ed[v].size(); i++) {
			ED &e = Ed[v][i];
			if(e.fl > 0 && D[e.to] > D[v] + e.co) {
				D[e.to] = D[v] + e.co;
				Wh[e.to] = v; Ix[e.to] = i;
				if(inQ[e.to] == false) Q.push(e.to), inQ[e.to] = true;
			}
		}
	}
	return D[En] != 1e9;
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		init();

		int flow = 0, cost = 0;
		while(spfa()) {
			int minF = 1e9;
			for(int w=En, i, v, r; w!=St; w=v) {
				i = Ix[w], v = Wh[w]; r = Ed[v][i].re;
				minF = min(minF, Ed[v][i].fl);
			}
			for(int w=En, i, v, r; w!=St; w=v) {
				i = Ix[w], v = Wh[w]; r = Ed[v][i].re;
				Ed[v][i].fl -= minF;
				Ed[w][r].fl += minF;
			}
			flow += minF;
			cost += minF * D[En];
		}
		printf("%d\n", cost);

		[&]() {
			for(int i=1; i<=N; i++) {
				vector<int> temp;
				E[i].swap(temp);
			}
			for(int i=St; i<=En; i++) {
				vector<ED> temp;
				Ed[i].swap(temp);
			}
		}();
	}
	return 0;
}