#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e2 + 10;

typedef long long ll;

ll Cost[MAX_N][MAX_N];
int N, Match[MAX_N], Nr[2][MAX_N][2];
bool Visit[MAX_N];

bool findMatch(int v, ll maxC) {
	if(Visit[v]) return false; Visit[v] = true;
	for(int w=0; w<N; w++) if(Cost[v][w] <= maxC)
		if(Match[w] == -1 || findMatch(Match[w], maxC)) {
			Match[w] = v;
			return true;
		}
	return false;
}
bool haveMatch(ll maxC) {
	for(int i=0; i<N; i++) Match[i] = -1;
	int flow = 0;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) Visit[j] = false;
		if(findMatch(i, maxC)) flow++;
	}
	return flow == N;
}

int main() {
	scanf("%d", &N);
	for(int k=0; k<2; k++) for(int i=0; i<N; i++) for(int j=0; j<2; j++) scanf("%d", &Nr[k][i][j]);
	for(int i=0; i<N; i++) for(int j=0; j<N; j++)
		Cost[i][j] = 1ll * abs(Nr[0][i][0] - Nr[1][j][0]) + abs(Nr[0][i][1] - Nr[1][j][1]);

	ll res = -1;
	for(ll l=0, r = 0x7ffffffff; l<=r;) {
		ll m = (l + r) / 2;
		if(haveMatch(m)) res = m, r = m-1;
		else l = m+1;
	}
	printf("%lld\n", res);
	return 0;
}