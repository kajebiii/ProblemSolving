#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 5e2 + 10, MAX_S = 1e5;

int N, Nr[MAX_N], Sum;
int Dy[2][MAX_S * 2 + 1];
int main() {
	scanf("%d", &N); for(int i=1; i<=N; i++) scanf("%d", &Nr[i]), Sum += Nr[i];
	for(int i=0; i<=2*MAX_S; i++) Dy[0][i] = -MAX_S * 2;
	Dy[0][MAX_S] = 0;
	for(int i=1; i<=N; i++) {
		for(int j=0; j<=2*MAX_S; j++) 
			Dy[i%2][j] = Dy[1-i%2][j];
		for(int j=Nr[i]; j<=2*MAX_S; j++)
			Dy[i%2][j] = max(Dy[i%2][j], Dy[1-i%2][j-Nr[i]] + Nr[i]);
		for(int j=0; j<=2*MAX_S-Nr[i]; j++)
			Dy[i%2][j] = max(Dy[i%2][j], Dy[1-i%2][j+Nr[i]]);
	}
	printf("%d\n", Sum - Dy[N%2][MAX_S]);
	return 0;
}