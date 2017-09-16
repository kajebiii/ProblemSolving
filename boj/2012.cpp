#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 5e5 + 100;

int N, Nr[MAX_N];
int main() {
	scanf("%d", &N); for(int i=0, x; i<N; i++) scanf("%d", &x), Nr[x]++;
	int cnt = 0; long long ans = 0;
	for(int i=1; i<MAX_N; i++) 
		while(Nr[i] > 0) {
			ans += abs(++cnt - i);
			Nr[i]--;
		}
	printf("%lld\n", ans);
	return 0;
}