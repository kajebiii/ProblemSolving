#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 2e2 + 100;

typedef long long ll;

int Q, N, D;
ll Dy[MAX_N][MAX_N];
int Nr[2][MAX_N];

int main() {
	scanf("%d%d%d", &Q, &N, &D);
	for(int j=0; j<2; j++) for(int i=1; i<=N; i++) scanf("%1d", &Nr[j][i]);

	Dy[0][0] = 1;
	for(int i=1; i<=N; i++) {
		for(int j=0; j<=D; j++) {
			if(Nr[0][i] != Nr[1][i]) {
				Dy[i][j+1] += Dy[i-1][j] * 2;
				Dy[i][j+2] += Dy[i-1][j] * (Q-2);
			} else {
				Dy[i][j] += Dy[i-1][j];
				Dy[i][j+2] += Dy[i-1][j] * (Q-1);
			}
		}
	}
	printf("%lld\n", Dy[N][D]);
	return 0;
}