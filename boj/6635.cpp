#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int N; char S[22];
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
	while(scanf("%s", S) == 1) {
		if(S[0] == 'e') break;
		int N = strlen(S);
		auto chk = [&]() {
			int cnt = 0, ix = -1;
			for(int i=0; i<N; i++) if(S[i] == '/') cnt++, ix = i;
			return cnt == 1 && ix == 6 && (N == 11 || N == 10);
		};
		if(chk() == false) {puts("invalid"); continue; }
		for(int i=6; i<N; i++) S[i] = S[i+1]; S[N-1] = 0;
		long long val; sscanf(S, "%lld", &val);
		if(N == 11 && val % 11 != 0) { puts("invalid"); continue; }
		int y, m, d; sscanf(S, "%02d%02d%02d", &y, &m, &d);
		if(y >= 10 && y < 20) { puts("invalid"); continue; }
		if(y >= 20 && y <= 53 && N == 11) { puts("invalid"); continue; }
		if( (y > 53 || y < 10) && N == 10) { puts("invalid"); continue; }

		bool isMale = true;
		if(m >= 51) m -= 50, isMale = false;
		if(m < 1 || m > 12 || d < 1 || d > 31) { puts("invalid"); continue; }
		bool isLeap = false;
		if( (y % 4 == 0 && y % 100 != 0) || y % 400 == 0) isLeap = true;
		if(isLeap) day[2] = 29; else day[2] = 28;
		if(d > day[m]) {puts("invalid"); continue;}
		puts(isMale?"boy":"girl");
	}
	return 0;
}