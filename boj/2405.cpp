#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 100;

int N, Nr[MAX_N];

int main()
{
	scanf("%d", &N); for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	sort(Nr, Nr+N);
	int ans = 0;
	for(int i=1; i+1<N; i++) ans = max(ans, abs(Nr[i+1]+Nr[0] - Nr[i]*2));
	for(int i=0; i+2<N; i++) ans = max(ans, abs(Nr[i]+Nr[N-1] - Nr[i+1]*2));
	printf("%d\n", ans);
	return 0;
}