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

int main() {
	set<int> S;
	while(true) {
		int x; scanf("%d", &x);
		if(x == -1) break;
		if(x == 0) {
			int ans = 0;
			for(int x : S) ans += S.count(2*x);
			printf("%d\n", ans);
			S.clear();
		}else{
			S.insert(x);
		}
	}
	return 0;
}


