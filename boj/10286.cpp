#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		int N; scanf("%d", &N);
		if(N % 10 < 5) N /= 10;
		else N = N / 10 + 1;
		if(N == 0) N += 18;
		if(N > 18) N -= 18;
		printf("%02d\n", N);
	}
	return 0;
}