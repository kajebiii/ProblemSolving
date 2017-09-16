#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 2e1 + 5;

int N, M;
char Mp[MAX_N][MAX_N];

int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d%d", &N, &M);
		for(int i=0; i<N; i++) scanf("%s", Mp[i]);

		int dual = 0, wc = 0, bc = 0, all = 0;
		for(int j=0; j<M; j++) {
			int b = -1, w = -1;
			for(int i=0; i<N; i++) {
				if(Mp[i][j] == 'B') b = i;
				if(Mp[i][j] == 'W') w = i;
			}
			if(w == N-1 && b == 0 && N > 3) dual++;
			else {
				if(b == 0 && w > 2) wc += w-2;
				if(w == N-1 && b < N-3) bc += N-3 - b;
				all += (w-b-1);
			}
		}
		bool whiteWin = false;
		if(N == 4 && dual % 2 == 1) whiteWin = true;
		if(wc < bc) whiteWin = true;
		if((wc == bc || wc == bc + 1) && all % 2 == 1) whiteWin = true;
		printf("%s wins\n", whiteWin?"White":"Black");
	}
	return 0;
}