#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAX_N = 222;
int T, N;
char S[MAX_N];

int type(char x) {
	if(x >= 'A' && x <= 'Z') return 0;
	if(x >= 'a' && x <= 'z') return 1;
	return 2;
}
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%s", S);
		N = strlen(S);
		int cnt[3] = {0, 0, 0}, all = 0;
		int j = 0;
		int ans = 0x7fffffff;
		for(int i=0; i<N; i++) {
			cnt[type(S[i])]++; all++;
			while(cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0 && all >= 6) {
				ans = min(ans, all);
				cnt[type(S[j])]--; j++; all--;
			}
		}
		if(ans == 0x7fffffff) ans = 0;
		printf("%d\n", ans);
	}
	return 0;
}