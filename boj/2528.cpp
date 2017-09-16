#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)((v).size()))
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 3e3 + 100;

int N, L, Nr[MAX_N][2];
pi getI(int ix, int t) {
	int a = 0, b = Nr[ix][0];
	int type = Nr[ix][1];
	if(L == b) return pi(a, b);
	t %= (L - b) * 2;
	if(t >= (L-b)) t -= (L-b), type = 1 - type;
	if(type == 1) t = (L-b) - t;
	return pi(a + t, b + t);
}
int main() {
	cin >> N >> L;
	for(int i=1; i<=N; i++) for(int j=0; j<2; j++) scanf("%d", &Nr[i][j]);
	int nowT = 0;
	for(int i=1; i<N; i++) {
		while(true) {
			pi fr = getI(i, nowT), to = getI(i+1, nowT);
			if(min(fr.two, to.two) >= max(fr.one, to.one)) break;
			nowT++;
		}
	}
	printf("%d\n", nowT);
	return 0;
}


