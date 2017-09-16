#include <stdio.h>
#include <algorithm>

using namespace std;

const int fre = 0;
int N, M, K; char S[111][111];
int main() {
	if(fre) freopen("cowsignal.in", "r", stdin);
	if(fre) freopen("cowsignal.out", "w", stdout);
	scanf("%d%d%d", &N, &M, &K);
	for(int i=0; i<N; i++) scanf("%s", S[i]);
	for(int i=N-1; i>=0; i--) for(int j=M-1; j>=0; j--)
		for(int x=0; x<K; x++) for(int y=0; y<K; y++)
			S[i*K+x][j*K+y] = S[i][j];
	for(int i=0; i<K*N; i++) printf("%s\n", S[i]);
	return 0;
}