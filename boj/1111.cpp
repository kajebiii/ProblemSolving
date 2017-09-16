#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e2 + 10;

int N, Nr[MAX_N], Diff[MAX_N];
int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	for(int i=1; i<N; i++) Diff[i] = Nr[i] - Nr[i-1];

	if(N == 1) {puts("A"); return 0;}
	bool isSame = true;
	for(int i=2; i<N; i++) if(Diff[i] * Diff[1] != Diff[2] * Diff[i-1]) {isSame = false; break;}
	if(isSame == false) {puts("B"); return 0;}
	for(int i=2; i<N; i++) if(Diff[i-1] == 0 && Diff[i] != 0) {puts("B"); return 0;}
	if(Diff[1] == 0) { printf("%d", Nr[1]); return 0; }
	if(N == 2) {puts("A"); return 0;}
	if(Diff[2] % Diff[1] != 0) {puts("B"); return 0;}
	int A = Diff[2] / Diff[1];
	int B = Nr[1] - Nr[0] * A;
	printf("%d\n", A*Nr[N-1] + B);

	return 0;
}