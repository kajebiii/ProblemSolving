#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 2e3 + 50, INF = 0x7fffffff;

int N, M;
char Mp[MAX_N][MAX_N];
int Dy[MAX_N][MAX_N], W[MAX_N][MAX_N];

void print(int n, int m) {
	if(n+m > 2) print(n-1+W[n][m], m-W[n][m]);
	printf("%c", Mp[n][m]);
}
int main() {
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++) scanf("%s", Mp[i]+1);
	for(int i=1; i<=max(N, M); i++) Dy[0][i] = Dy[i][0] = INF/30;
	for(int p=3; p<=N+M; p++) {
		vector<int> Uni;
		for(int i=1; i<=N; i++) {
			int j = p - i;
			if(j > M) continue;
			if(j <= 0) break;
			if(Dy[i-1][j] < Dy[i][j-1]) {
				Dy[i][j] = Dy[i-1][j] * 26 + Mp[i][j] - 'a';
				W[i][j] = 0;
			}else {
				Dy[i][j] = Dy[i][j-1] * 26 + Mp[i][j] - 'a';
				W[i][j] = 1;
			}
			Uni.push_back(Dy[i][j]);
		}
		sort(Uni.begin(), Uni.end());
		Uni.erase(unique(Uni.begin(), Uni.end()), Uni.end());
		for(int i=1; i<=N; i++) {
			int j = p - i;
			if(j > M) continue;
			if(j <= 0) break;
			Dy[i][j] = lower_bound(Uni.begin(), Uni.end(), Dy[i][j]) - Uni.begin();
		}
	}
	print(N, M);
	return 0;
}