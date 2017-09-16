#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		char S[9]; int N, T, L;
		scanf("%s%d%d%d", S, &N, &T, &L);
		L *= 100000000;
		L /= T;
		long long val = 0;
		if(S[3] == ')') val = N;
		else if(S[4] == '2') val = 1ll * N * N;
		else if(S[4] == '3') val = 1ll * N * N * N;
		else if(S[3] == '^') {
			val = 1;
			for(int i=0; i<N; i++) {
				val *= 2;
				if(val > L) break;
			}
		} else if(S[3] == '!') {
			val = 1;
			for(int i=1; i<=N; i++) {
				val *= i;
				if(val > L) break;
			}
		}
		if(val > L) puts("TLE!");
		else puts("May Pass.");
	}
	return 0;
}