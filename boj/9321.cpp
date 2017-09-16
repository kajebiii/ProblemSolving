#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e4 + 100;

int N, M, S, Nr[MAX_N], Dy[MAX_N][2];
bool Vis[MAX_N][2];
vector<int> Ed[MAX_N];
int getDy(int v, int k) {
	int &val = Dy[v][k];
	if(Vis[v][k]) return val;
	Vis[v][k] = true;
	bool isTrue = false;
	int cnt = 0;
	for(int w : Ed[v]) {
		cnt++;
		if(Nr[v] == Nr[w] && getDy(w, 1-k)) return val = true;
		if(Nr[v] != Nr[w] && getDy(w, k) == false) return val = true;
	}
	if(cnt == 0 && k == 0)
		return val = true;
	return val = false;
}
int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d%d%d", &N, &M, &S);
		for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
		while(M--) {
			int x, y; scanf("%d%d", &x, &y);
			Ed[x].push_back(y); 
		}
		for(int i=1; i<=N; i++) for(int j=0; j<2; j++) Vis[i][j] = false;
		printf("%d\n", (Nr[S] + getDy(S, Nr[S]) + 1) % 2 );

		for(int i=1; i<=N; i++) {Ed[i].clear(); Ed[i].shrink_to_fit(); }
	}
	return 0;
}