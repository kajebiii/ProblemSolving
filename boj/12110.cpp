#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 3e5 + 300;

int N, D, Nr[MAX_N];
int main() {
	scanf("%d%d", &N, &D);
	for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);

	int l = 1, r = 1;
	int ans = 0;
	while(l <= r && r < N) {
		if(Nr[l] == 1) r = max(r, l + D);
		if(l == r) ans++, r = max(r, l + D);
		l++;
	}
	printf("%d\n", ans);
	return 0;
}