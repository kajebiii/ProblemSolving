#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

char S[88]; int N;
int main() {
	while(scanf("%s", S) == 1) {
		N = strlen(S);
		if(N == 1 && S[0] == '*') break;
		bool isTrue = true;
		for(int p=0; p<=N-2; p++) {
			bool nowGood = true;
			map<int, bool> Mp;
			for(int i=0; i<N-p-1; i++) {
				int j = i + p+1;
				if(Mp[S[i] * 1000 + S[j]] == true) {nowGood = false; break;}
				Mp[S[i] * 1000 + S[j]] = true;
			}
			if(nowGood == false) {isTrue = false; break;}
		}
		printf("%s is ", S);
		if(isTrue) puts("surprising.");
		else puts("NOT surprising.");
	}
	return 0;
}