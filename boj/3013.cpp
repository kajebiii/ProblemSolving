#include <stdio.h>

const int MAX_N = 1e5 + 100;

int Compare[MAX_N], Nr[MAX_N], N, B;
int RightSum[MAX_N*2];
int main()
{
	scanf("%d%d", &N, &B);
	for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
	int ix = -1;
	for(int i=1; i<=N; i++) if(Nr[i] == B) ix = i;
	for(int i=ix+1; i<=N; i++) Compare[i] = Compare[i-1] + ((Nr[i] > B) * 2 - 1);
	for(int i=ix; i<=N; i++) RightSum[Compare[i] + N]++;
	for(int i=ix-1; i>=1; i--) Compare[i] = Compare[i+1] + ((Nr[i] > B) * 2 - 1);
	long long ans = 0;
	for(int i=1; i<=ix; i++)
		ans += RightSum[N - Compare[i]];
	printf("%lld", ans);
	return 0;
}