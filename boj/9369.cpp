#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <string.h>

using namespace std;

const int MAX_N = 1e2 + 10;

int N; string S[MAX_N], D, X;
int Chk[26], Cnt[26][26], BChk[26], Mat[26];
void getS(string &s) {
	char st[1111]; scanf("%s", st);
	s = st;
}
int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d", &N);
		for(int i=0; i<N; i++) getS(S[i]);
		getS(D); getS(X);

		int cnt = 0, l = D.length();
		for(int i=0; i<26; i++) for(int j=0; j<26; j++) Cnt[i][j] = 0;
		for(int s=0; s<N; s++) {
			if(l != S[s].length()) continue;
			for(int i=0; i<26; i++) Chk[i] = BChk[i] = -1;
			bool impossible = false;
			for(int i=0; i<l; i++) {
				int si = S[s][i] - 'a', di = D[i] - 'a';
				if(Chk[si] == -1) Chk[si] = di;
				if(Chk[si] != di) { impossible = true; break; }
				if(BChk[di] == -1) BChk[di] = si;
				if(BChk[di] != si) {impossible = true; break;}
			}
			if(impossible) continue;
			cnt++;
			for(int i=0; i<26; i++)
				if(Chk[i] != -1) Cnt[i][Chk[i]]++;
		}
		if(cnt == 0) {puts("IMPOSSIBLE"); continue;}
		int match = 0, sum = 0;
		for(int x=0; x<26; x++) {
			Mat[x] = -1;
			for(int i=0; i<26; i++)
				if(Cnt[x][i] == cnt) {
					match++;
					sum += i;
					Mat[x] = i;
				}
		}
		if(match == 25) {
			for(int x=0; x<26; x++) {
				bool isMatch = false;
				for(int i=0; i<26; i++) if(Cnt[x][i] == cnt) isMatch = true;
				if(!isMatch) Mat[x] = (26 * 25) / 2 - sum;
			}
		}
		for(char x : X) {
			char val = '?';
			if(Mat[x-'a'] != -1) val = Mat[x-'a'] + 'a';
			printf("%c", val);
		}
		puts("");
	}
	return 0;
}