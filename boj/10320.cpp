#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_T = 3600, MAX_N = 2e1 + 5, INF = 0x7fffffff;

int N, T, Nr[MAX_N];

int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d%d", &N, &T);
		for(int i=0; i<N; i++) scanf("%d", &Nr[i]);

		vector<int> dis = vector<int>(MAX_T+1, INF);
		queue<int> Q; Q.push(0); dis[0] = 0;
		while(!Q.empty()) {
			int v = Q.front(); Q.pop();
			for(int i=0; i<N; i++) {
				int w = v + Nr[i];
				if(w < 0) w = 0;
				if(w > MAX_T) w = MAX_T;
				if(dis[w] != INF) continue;
				dis[w] = dis[v] + 1;
				Q.push(w);
			}
		}
		for(int i=T; i<=MAX_T; i++) if(dis[i] != INF) {
			printf("%d %d\n", dis[i], i-T);
			break;
		}
	}
	return 0;
}