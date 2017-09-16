#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 5e4 + 10;

int N, K, Nr[MAX_N];
int main()
{
//	freopen("diamond.in", "r", stdin);
//	freopen("diamond.out", "w", stdout);
	scanf("%d%d", &N, &K);
	for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	sort(Nr, Nr+N);
	int ans = 0;
	for(int i=0; i<N; i++) 
		ans = max(ans, (int)(upper_bound(Nr, Nr+N, Nr[i]+K) - Nr - i) );
	printf("%d\n", ans);
	return 0;
}