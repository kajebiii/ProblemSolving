#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 2e3 + 100, INF = 0x7fffffff;

int N, Nr[MAX_N][2]; // when we win | delegate
int Dy[MAX_N];
int main() {
	scanf("%d", &N);
	int sum = 0;
	for(int i=0; i<N; i++) {
		int d, a, b, c; scanf("%d%d%d%d", &d, &a, &b, &c);
		Nr[i][1] = d;
		if(b+c < a) Nr[i][0] = 0;
		else if(a+c <= b) Nr[i][0] = INF;
		else Nr[i][0] = (b+c-a)/2 + 1;
		sum += d;
	}
	int toWin = sum / 2 + 1;
	for(int p=sum; p>=0; p--) Dy[p] = INF; Dy[0] = 0;
	for(int i=0; i<N; i++) {
		if(Nr[i][0] == INF) continue;
		for(int p=sum; p>=0; p--) {
			if(Dy[p] == INF) continue;
			Dy[p+Nr[i][1]] = min(Dy[p+Nr[i][1]], Dy[p]+Nr[i][0]);
		}
	}
	int ans = INF;
	for(int p=toWin; p<=sum; p++) ans = min(ans, Dy[p]);
	if(ans == INF) puts("impossible");
	else printf("%d\n", ans);
	return 0;
}