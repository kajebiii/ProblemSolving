#include <stdio.h>
#include <algorithm>

using namespace std;

const int fre = 0;
int Cnt[26];
int main() {
	if(fre) freopen("blocks.in", "r", stdin);
	if(fre) freopen("blocks.out", "w", stdout);
	int N; scanf("%d", &N);
	for(int n=0; n<N; n++) {
		char S[2][99];
		for(int j=0; j<2; j++) scanf("%s", S[j]);
		for(int k=0; k<26; k++) {
			int maxV = 0;
			for(int j=0; j<2; j++) {
				int cnt = 0;
				for(int i=0; S[j][i]; i++) 
					if(S[j][i] == 'a' + k) cnt++;
				maxV = max(maxV, cnt);
			}
			Cnt[k] += maxV;
		}
	}
	for(int i=0; i<26; i++) printf("%d\n", Cnt[i]);
	return 0;
}