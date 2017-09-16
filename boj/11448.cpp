#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int MAX_N = 1e2 + 10;

typedef pair<int, int> pi;

int N; char Mp[MAX_N][MAX_N];
bool Chk[MAX_N][MAX_N];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &N); for(int i=0; i<N; i++) scanf("%s", Mp[i]);
		for(int i=0; i<N; i++) for(int j=0; j<N; j++) Chk[i][j] = false;

		queue<pi> Q;
		for(int i=0; i<N; i++) for(int j=0; j<N; j++)
			if(Mp[i][j] == 'w') {
				for(int k=0; k<8; k++) {
					int x = i + "10120202"[k] - '1';
					int y = j + "01210022"[k] - '1';
					if(x<0 || y<0 || x>=N || y>=N) continue;
					if(Chk[x][y]) continue;
					if(Mp[x][y] != '-') continue;
					Chk[x][y] = true;
					Q.push(make_pair(x, y));
				}
			}

		int ans = 0;
		while(!Q.empty()) {
			int i, j; tie(i, j) = Q.front(); Q.pop();
			ans++;
			for(int k=0; k<8; k++) {
				int x = i + "10120202"[k] - '1';
				int y = j + "01210022"[k] - '1';
				if(x<0 || y<0 || x>=N || y>=N) continue;
				if(Chk[x][y]) continue;
				if(Mp[x][y] != '-') continue;
				Chk[x][y] = true;
				Q.push(make_pair(x, y));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}