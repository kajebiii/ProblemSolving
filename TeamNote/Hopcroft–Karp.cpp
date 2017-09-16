#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define REPO(i,n) for(int (i)=1; (i)<=(int)(n); (i)++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 1e3 + 10;

int N;
vector<int> Ed[MAX_N];
int lv[MAX_N], lm[MAX_N], rm[MAX_N], ix[MAX_N];
void bfs() {
	queue<int> Q;
	REP(i, N) if(lm[i] != -1) lv[i] = INF;
	else lv[i] = 0, Q.push(i);
	while(!Q.empty()) {
		int v = Q.front(); Q.pop();
		for(int w : Ed[v]) if(rm[w] != -1 && lv[rm[w]] == INF)
			lv[rm[w]] = lv[v] + 1, Q.push(rm[w]);
	}
}
bool dfs(int v) {
	for(int &i=ix[v]; i<SZ(Ed[v]); i++) {
		int w = Ed[v][i];
		if(rm[w] == -1 || lv[rm[w]] == lv[v] + 1 && dfs(rm[w])) {
			lm[v] = w, rm[w] = v;
			return true;
		}
	}
	return false;
}
int main() {
	cin >> N;
	REP(i, N) {
		int k; scanf("%d", &k);
		REP(j, k) {
			int x; scanf("%d", &x);
			Ed[i].push_back(x);
		}
	}

	REP(i, N) lm[i] = rm[i] = -1;
	int ans = 0;
	while(true) {
		bfs(); int f=0;
		REP(i, N) ix[i] = 0;
		REP(i, N) if(lm[i] == -1 && dfs(i)) f++;
		if(f == 0) break;
		ans += f;
	}
	printf("%d\n", N - ans);
	return 0;
}