#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 5e6 + 100;

int N, Nr[MAX_N];

int main()
{
	long long sum = 0;
	scanf("%d", &N); for(int i=0; i<N; i++) scanf("%d", &Nr[i]), sum += Nr[i];
	sort(Nr, Nr+N);
	printf("%d ", Nr[(N-1)/2]);
	long long ans = sum / N; sum %= N;
	if(sum > N/2) ans++;
	printf("%lld\n", ans);
	return 0;
}