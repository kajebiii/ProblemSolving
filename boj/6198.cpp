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

int N; stack<int> S;
int main() {
	cin >> N;
	S.push(INF);
	ll ans = 0;
	for(int i=0; i<N; i++) {
		int x; scanf("%d", &x);
		while(S.top() <= x) S.pop();
		S.push(x);
		ans += SZ(S) - 2;
	}
	printf("%lld\n", ans);
	return 0;
}


