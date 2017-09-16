#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 5e4 + 10;

int N, K, Nr[MAX_N], MaxDy[MAX_N];
int main()
{
	scanf("%d%d", &N, &K);
	for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	sort(Nr, Nr+N);
	int ans = 0;
	for(int i=N-1; i>=0; i--)
		MaxDy[i] = max(MaxDy[i+1], (int)(upper_bound(Nr, Nr+N, Nr[i]+K) - Nr - i));
	for(int i=0; i<N; i++)
	{
		int ix = (int)(upper_bound(Nr, Nr+N, Nr[i]+K) - Nr);
		ans = max(ans, (ix - i) + MaxDy[ix]);
	}
	printf("%d\n", ans);
	return 0;
}