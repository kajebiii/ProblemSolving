#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

const int MAX_N = 1e3 + 100;

int N, K;
string S[MAX_N]; bool Chk[MAX_N], Known[MAX_N];
int main() {
	scanf("%d%d", &N, &K);
	while(K--) {
		char x[33], y[33]; int a, b;
		scanf("%d%d%s%s", &a, &b, x, y);
		S[a] = x; S[b] = y;
		Known[a] = Known[b] = true;
		if(S[a] == S[b]) Chk[a] = Chk[b] = true;
	}
	int nowN = 0; for(int i=1; i<=N; i++) if(Chk[i] == false) nowN++;
	int ans = 0, kind = 0;
	for(int i=1; i<=N; i++) {
		if(Known[i] == false) continue;
		if(Chk[i] == true) continue;
		for(int j=i+1; j<=N; j++) 
			if(S[i] == S[j]) {
				Chk[i] = Chk[j] = true;
				nowN -= 2;
				ans++;
			}
	}
	for(int i=1; i<=N; i++) {
		if(Known[i] == false) continue;
		if(Chk[i] == true) continue;
		kind++;
	}
	if(kind * 2 == nowN) ans += kind;
	if(kind == 0 && nowN == 2) ans++;
	printf("%d\n", ans);
	return 0;
}