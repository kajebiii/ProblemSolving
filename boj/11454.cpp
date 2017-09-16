#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

const int MAX_N = 1e5 + 100;

int Cnt[26]; char S[MAX_N], Ans[MAX_N]; int N;
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%s", S); N = strlen(S);
		for(int i=0; i<26; i++) Cnt[i] = 0;
		for(int i=0; i<=N; i++) Ans[i] = 0;
		for(int i=0; i<N; i++) Cnt[S[i]-'a']++;

		bool isPos = true;
		for(int i=0; i<26; i++) if(Cnt[i] > (N+1)/2) isPos = false;
		if(!isPos) {puts("IMPOSSIBLE"); continue;}

		int rM[50], lM[50];
		for(int i=0; i<N; i++) {
			for(int j=0; j<26; j++) rM[j] = lM[j] = 0;
			lM[0] = Cnt[0]; for(int j=1; j<26; j++) lM[j] = max(lM[j-1], Cnt[j]);
			rM[25] = Cnt[25]; for(int j=24; j>=0; j--) rM[j] = max(rM[j+1], Cnt[j]);
			for(int j=0; j<26; j++) {
				if(i > 0 && Ans[i-1] - 'a' == j) continue;
				int n = Cnt[j] - 1; if(n < 0) continue;
				int l = 0; if(j > 0) l = lM[j-1];
				int r = 0; if(j < 26-1) r = rM[j+1];

				int limit = (N-i-1 + 1) / 2;
				if(l > limit || n > limit || r > limit) continue;
				Ans[i] = 'a' + j;
				Cnt[j]--;
				break;
			}
		}
		printf("%s\n", Ans);
	}
	return 0;
}