#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int X, N, M;
bool PROCESS() {
	scanf("%d%d%d", &X, &N, &M);
	if(N > M) swap(N, M);
	int all = N*M;
	if(all%X != 0) return false;
	if(X >= 7) return false;
	if(X <= 2) return true;
	if(X == 3) return N > 1;
	if(X == 4) return N > 2;
	if(X == 6) return N > 3;
	if(X == 5) {
		if(N <= 2) return false;
		if(all == 15) return false;
		return true;
	}
	return true;
}

int main() {
	int T; scanf("%d", &T);

	for(int i=1; i<=T; i++)
		printf("Case #%d: %s\n", i, PROCESS()?"GABRIEL":"RICHARD");

	return 0;
}
