#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 2e1 + 10;

int N, Nr[MAX_N][2], Dy[MAX_N];
int main() {
	scanf("%d", &N); for(int i=1; i<=N; i++) for(int j=0; j<2; j++) scanf("%d", &Nr[i][j]);
	for(int i=1; i<=N+1; i++) {
		Dy[i] = max(Dy[i], Dy[i-1]);
		Dy[i+Nr[i][0]] = max(Dy[i+Nr[i][0]], Dy[i] + Nr[i][1]);
	}
	printf("%d\n", Dy[N+1]);
	return 0;
}