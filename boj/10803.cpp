#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e2 + 10, MAX_M = 1e4 + 100;

int N, M;
int Dy[MAX_N][MAX_M];

int main() {
	scanf("%d%d", &N, &M);
	if(N >= M) swap(N, M);
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) {
		if(i == j)  Dy[i][j] = 1;
		else if(i * 4 <= j) Dy[i][j] = 1 + Dy[i][j-i]; 
		else{
			Dy[i][j] = 0x7fffffff;
			for(int k=1; k<j; k++)
				Dy[i][j] = min(Dy[i][j],Dy[i][k] + Dy[i][j-k]);
			for(int k=1; k<i; k++)
				Dy[i][j] = min(Dy[i][j],Dy[k][j] + Dy[i-k][j]);
		}
	}
	printf("%d\n",Dy[N][M]);
	return 0;
}