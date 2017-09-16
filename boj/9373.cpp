#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

const int MAX_N = 1e3 + 10, ITER = 60;

int W, N, Nr[MAX_N][3];
double getDis(int a, int b) {
	if(a > b) swap(a, b);
	if(a == 0 && b == N+1) return W;
	if(a == 0) return max(0, Nr[b][0] - Nr[b][2]);
	if(b == N+1) return max(0, W - Nr[a][0] - Nr[a][2]);
	int dx = Nr[a][0] - Nr[b][0], dy = Nr[a][1] - Nr[b][1];
	return max(0.0, sqrt(1ll * dx * dx + 1ll * dy * dy) - Nr[a][2] - Nr[b][2]);
}
int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d%d", &W, &N);
		for(int i=1; i<=N; i++) for(int j=0; j<3; j++) scanf("%d", &Nr[i][j]);
		auto isPossible = [&](double m) {
			queue<int> Q; Q.push(0); 
			vector<int> list;
			for(int i=1; i<=N+1; i++) list.push_back(i);
			while(!Q.empty()) {
				int v = Q.front(); Q.pop();
				for(auto it = list.begin(); it != list.end(); ) {
					int w = *it;
					if(getDis(v, w) < m) {
						Q.push(w);
						if(w == N+1) return false;
						it = list.erase(it);
					}else it++;
				}
			}
			return true;
		};
		double ans = -1; int cnt = 0;
		for(double l=0, r=W; l<=r && cnt < ITER; cnt++) {
			double m = (l+r) / 2;
			if(isPossible(m)) ans = m, l = m;
			else r = m;
		}
		if(ans < 0) ans = 0;
		printf("%.10f\n", ans / 2);
	}
	return 0;
}