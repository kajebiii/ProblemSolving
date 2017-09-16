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

int N, K; char S[MAX_N];
map<int, set<int> > Xs, Ys;
int X, Y;
void deleteNow() {
	Xs[X].erase(Y);
	Ys[Y].erase(X);
}
int main() {
	cin >> N >> K;
	scanf("%s", S);
	for(int i=0; i<N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		int x = a+b, y = a-b;
		if(!i) X=x, Y=y;
		Xs[x].insert(y);
		Ys[y].insert(x);
	}
	for(int k=0; k<K; k++) {
		char c = S[k];
		if(c == 'B' || c == 'C') {
			if(c == 'B') {
				auto it = Xs[X].upper_bound(Y);
				if(it != Xs[X].end()) {
					deleteNow();
					Y = *it;
				}
			}else{
				auto it = Xs[X].lower_bound(Y);
				if(it != Xs[X].begin()) {
					it--;
					deleteNow();
					Y = *it;
				}
			}
		}else{
			if(c == 'A') {
				auto it = Ys[Y].upper_bound(X);
				if(it != Ys[Y].end()) {
					deleteNow();
					X = *it;
				}
			}else{
				auto it = Ys[Y].lower_bound(X);
				if(it != Ys[Y].begin()) {
					it--;
					deleteNow();
					X = *it;
				}
			}
		}
	}
	printf("%d %d\n", (X+Y)/2, (X-Y)/2);
	return 0;
}


