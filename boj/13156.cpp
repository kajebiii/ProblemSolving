#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long ll;
typedef pair<int, int> pi;

const int MAX_N = 1e2 + 10;

int N, M, Dy[MAX_N][MAX_N];

int main() {
	scanf("%d%d", &N, &M);
	for(int k=1; k<=M; k++) {
		int val[MAX_N] = {0};
		for(int i=1; i<=N; i++) scanf("%d", &val[i]);
		for(int i=0; i<=N; i++) for(int j=i; j<=N; j++)
			Dy[k][i] = max(Dy[k][i], Dy[k-1][j] + val[j-i]);
	}
	printf("%d\n", Dy[M][0]);
	return 0;
}