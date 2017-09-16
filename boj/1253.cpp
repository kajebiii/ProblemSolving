#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 2e3 + 100;

int N, Nr[MAX_N];
int main() {
	scanf("%d", &N); for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	sort(Nr, Nr+N);
	int ans = 0;
	for(int i=0; i<N; i++) {
		bool isTrue = false;
		for(int j=0; j<N; j++) if(i != j) {
			int l = lower_bound(Nr, Nr+N, Nr[i] - Nr[j]) - Nr;
			int r = upper_bound(Nr, Nr+N, Nr[i] - Nr[j]) - Nr;
			int cnt = r - l;
			if(l <= i && i < r) cnt--;
			if(l <= j && j < r) cnt--;
			if(cnt > 0) {isTrue = true; break;}
		}
		if(isTrue) ans++;
	}
	printf("%d\n", ans);
	return 0;
}