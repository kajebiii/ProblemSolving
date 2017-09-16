#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 5e3 + 10, MOD = 5318008;

int Dy[MAX_N][MAX_N];
int main() {
	int TC; scanf("%d", &TC);
	for(int tc=1; tc<=TC; tc++) {
		int L, X0, Y0, X1, Y1;
		scanf("%d%d%d%d%d", &L, &X0, &Y0, &X1, &Y1);
		if(abs(X0 - X1) < abs(Y0 - Y1)) swap(X0, Y0), swap(X1, Y1);
		if(X0 > X1) swap(X0, X1), swap(Y0, Y1);
		int N = X1 - X0, M = L;
		for(int i=1; i<=L; i++) Dy[0][i] = 0; Dy[0][Y0] = 1;
		for(int i=0; i<=N; i++) Dy[i][0] = Dy[i][L+1] = 0;
		for(int i=1; i<=N; i++) for(int j=1; j<=L; j++) {
			Dy[i][j] = 0;
			for(int k=-1; k<=1; k++) Dy[i][j] += Dy[i-1][j+k];
			Dy[i][j] %= MOD;
		}
		printf("%d\n", Dy[N][Y1]);
	}
	return 0;
}