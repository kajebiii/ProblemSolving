#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

const int MAX_N = 5e3 + 100;

int N, D, Nr[MAX_N], Diff[MAX_N];
char cheat[99] = "CHEATERS!";
void solve() {
	scanf("%d%d", &N, &D);
	for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	bool impos = false;
	for(int i=0; i<N-2*D; i++) if(Nr[i] != Nr[i+2*D]) impos = true;
	if(impos) {puts(cheat); return;}

	N = 2 * D; // because period is 2 * D;
	rep(i, N) {
		if(i == 0) Diff[i] = Nr[0] - Nr[N-1];
		else Diff[i] = Nr[i] - Nr[i-1];
	}
//	rep(i, N) printf("%02d ", Diff[i]); puts("");
	int ans = 0;
	for(int d = D; d >= 1; d /= 2) {
		for(int k=0; k<d; k++) {
			int block = N / d;
			int sum = 0;
			for(int i=k, m=1; i<N; i+=d, m*=-1)
				sum += m * Diff[i];
			if(sum % block != 0) { puts(cheat); return; }
			int val = (sum / block);
			ans += abs(val);
			for(int i=k, m=1; i<N; i+=d, m*=-1) {
				Diff[i] -= m * val;
				if(m * val > 0) for(int l=i; l<i+d; l++) Nr[(l%N)] -= abs(val);
			}
//			printf("[%d %d] : ", d, k); rep(i, N) printf("%02d ", Diff[i]); puts("");
		}
	}
	rep(i, N) if(Diff[i] != 0) { puts(cheat); return; }
	rep(i, N) if(Nr[i] < 0) { puts(cheat); return; }
//	rep(i, N) printf("%d ", Nr[i]); puts("");
	printf("%d\n", ans);
}

const int fre = 0;
int main() {
	if(fre) freopen("input.txt", "r", stdin);
	if(fre) freopen("output.txt", "w", stdout);

	int TC; scanf("%d", &TC);
	for(int tc=1; tc<=TC; tc++) {
		printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}