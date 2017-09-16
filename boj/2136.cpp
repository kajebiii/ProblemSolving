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

const int MAX_N = 1e5 + 100;

int N, L;
vector<pi> Nr;
int getT(int x) {
	if(x < 0) return -x;
	return L-x;
}
int main() {
	cin >> N >> L;
	int ms = 0;
	for(int i=0; i<N; i++) {
		int x; scanf("%d", &x);
		Nr.push_back(pi(x, i));
		if(x < 0) ms++;
	}
	sort(ALL(Nr), [&](pi a, pi b) {
		return getT(a.one) < getT(b.one);
	});
	int ix = ms;
	if(Nr.back().one < 0) ix--;

	int ansT = getT(Nr.back().one);
	sort(ALL(Nr), [&](pi a, pi b){
		return abs(a.one) < abs(b.one);
	});
	ix = Nr[ix].two;
	printf("%d %d\n", ix+1, ansT);
	return 0;
}


