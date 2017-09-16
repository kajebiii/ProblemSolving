#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 16;

int N, M;
vector<int> Ed[MAX_N];
int Color[MAX_N]; bool Chk[MAX_N];

bool dfs(int v, int c) {
	if(Color[v] != 0) {
		if(Color[v] == c) return true;
		else return false;
	}
	Color[v] = c;
	int nc = 3 - c;
	for(int w : Ed[v]) if(Chk[w] == true && dfs(w, nc) == false) return false;
	return true;
}
int coloring(int s) {
	for(int i=0; i<N; i++) Color[i] = 0, Chk[i] = false;
	for(int i=0; i<N; i++) if(s & (1<<i)) Chk[i] = true;

	for(int i=0; i<N; i++) if(s & (1<<i)) if(Color[i] == 0)
		if(dfs(i, 1) == false) return 10;
	int maxC = -1;
	for(int i=0; i<N; i++) maxC = max(maxC, Color[i]);
	return maxC;
}
int main() {
	int TC; scanf("%d", &TC);
	for(int tc=1; tc<=TC; tc++) {
		scanf("%d%d", &N, &M);
		for(int i=0, x, y; i<M; i++) scanf("%d%d", &x, &y), Ed[x].push_back(y), Ed[y].push_back(x);
		int val = coloring((1<<N) - 1);
		if(val <= 2) printf("%d\n", val);
		else {
			for(int s=0; s<(1<<(N-1)); s++) {
				int nowVal = coloring(s) + coloring((1<<N) - 1 - s);
				val = min(val, nowVal);
				if(val == 3) break;
			}
			if(val <= 4) printf("%d\n", val);
			else puts("many");
		}
		for(int i=0; i<N; i++) Ed[i].clear(), Ed[i].shrink_to_fit();
	}
	return 0;
}