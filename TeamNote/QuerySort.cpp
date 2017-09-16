#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define REPO(i,n) for(int (i)=1; (i)<=(int)(n); (i)++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 1e5 + 100, MAX_V = 1 << 21, ROOT_N = 300;

int N, K, Nr[MAX_N], Q; ll Ans[MAX_N];
struct QQ {
	int x, y, ix, bk;
	QQ() {}
	QQ(int x_, int y_, int i_) : x(x_), y(y_), ix(i_), bk(x_/ROOT_N) {}
};
vector<QQ> Qs;
int outV[MAX_V], inV[MAX_V];

int main() {
	cin >> N >> K;
	Nr[0] = 0;
	REP(i, N) {
		scanf("%d", &Nr[i+1]);
		Nr[i+1] ^= Nr[i];
	}
	N++;

	cin >> Q;
	REP(i, Q) {
		int x, y;
		scanf("%d%d", &x, &y); x--;
		Qs.push_back(QQ(x, y, i));
	}
	sort(ALL(Qs), [&](const QQ &a, const QQ &b) {return (a.bk!=b.bk?a.bk<b.bk:a.y<b.y);});

	int r = -1; ll r_val = 0;
	REP(q, Q) {
		int bk = Qs[q].bk, x = Qs[q].x, y = Qs[q].y;
		if(q == 0 || bk != Qs[q-1].bk) {
			for(int i=0; i<N; i++) outV[Nr[i]] = 0;
			r = (bk+1) * ROOT_N;
			r_val = 0;
		}
		while(r <= y) {
			r_val += outV[Nr[r] ^ K];
			outV[Nr[r]]++;
			r++;
		}
		ll ans = r_val;

		for(int i=min(y, (bk+1) * ROOT_N - 1); i>=x; i--) {
			ans += outV[Nr[i] ^ K] + inV[Nr[i] ^ K];
			inV[Nr[i]]++;
		}
		for(int i=min(y, (bk+1) * ROOT_N - 1); i>=x; i--) inV[Nr[i]] = 0;

		Ans[Qs[q].ix] = ans;
	}
	REP(i, Q) printf("%lld\n", Ans[i]);
	return 0;
}