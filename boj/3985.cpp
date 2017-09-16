#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e3 + 10;

int L, N, Nr[MAX_N][2], Cnt[MAX_N], St[MAX_N];

int main()
{
	scanf("%d%d", &L, &N);
	int exV = -1, evIx = -1;
	for(int i=1; i<=N; i++) scanf("%d%d", &Nr[i][0], &Nr[i][1]);
	for(int i=1; i<=N; i++) if(exV < Nr[i][1] - Nr[i][0]) exV = Nr[i][1] - Nr[i][0], evIx = i;
	for(int i=N; i>=1; i--) for(int j=Nr[i][0]; j<=Nr[i][1]; j++) St[j] = i;
	for(int i=1; i<=L; i++) Cnt[St[i]]++;
	int reV = -1, reIx = -1;
	for(int i=1; i<=N; i++) if(reV < Cnt[i]) reV = Cnt[i], reIx = i;
	printf("%d\n%d\n", evIx, reIx);
	return 0;
}