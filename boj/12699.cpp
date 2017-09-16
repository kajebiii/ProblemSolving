#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 5e3 + 100;

int N, Cnt[2][3]; //0 read, 1 write
char S[MAX_N];

int main() {
	scanf("%d", &N);
	for(int p=0; p<2; p++) {
		scanf("%s", S);
		for(int i=0; i<N; i++)
			Cnt[1-p][S[i]-'a']++;
	}

	for(int i=0; i<N; i++) {
		for(int j=0; j<3; j++) {
			if(S[i] == (j+'a')) continue;
			if(Cnt[1][j] == 0) continue;
			Cnt[0][S[i]-'a']--;
			Cnt[1][j]--;

			bool chk = true;
			for(int k=0; k<3; k++)
				if(Cnt[1][k] > Cnt[0][(k+1)%3] + Cnt[0][(k+2)%3]) {
					chk = false;
					break;
				}
			if(chk == false) {
				Cnt[0][S[i]-'a']++;
				Cnt[1][j]++;
				continue;
			} else {
				S[i] = j+'a';
				break;
			}
		}
	}
	puts(S);
	return 0;
}