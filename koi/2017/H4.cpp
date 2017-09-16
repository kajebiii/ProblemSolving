#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, int> pli; typedef pair<ll, pi> plp;
typedef tuple<int, int, int> ti; typedef tuple<ll, int, int> tli;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 1500 + 100;

struct BIT {
	int val[MAX_N];
	BIT() {for(int i=0; i<MAX_N; i++) val[i] = 0;}
	void update(int v, int k) {for(v+=10; v<MAX_N; v+=v&-v) val[v] += k;}
	int getSum(int v) {int res = 0; for(v+=10; v; v-=v&-v) res += val[v]; return res;}
	int operator[](int k) {return getSum(k);}
};
int N, Nr[MAX_N][MAX_N], Dy[MAX_N][MAX_N];
BIT bit[MAX_N];
int main() {
	cin >> N; 
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) scanf("%d", &Nr[i][j]);
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) Dy[i][j] = max(Dy[i-1][j], Dy[i][j-1]) + Nr[i][j];
	for(int i=1; i<=N; i++) bit[i] = BIT();
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) {
		bit[i].update(j  , +Dy[i][j]);
		bit[i].update(j+1, -Dy[i][j]);
	}
	ll ans = 0;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) ans += Dy[i][j];
	printf("%lld\n", ans);

	for(int i=1; i<=N; i++) {
		char s[5]; int x, y, t = 1; scanf("%s%d%d", s, &x, &y);
		if(s[0] == 'D') t = -1;
		Nr[x][y] += t;
		int l = y, r = y+1;
		while(r <= N && bit[x][r] != max(bit[x][r-1] + t, bit[x-1][r]) + Nr[x][r]) r++;
		bit[x].update(l, t); bit[x].update(r, -t);
//		printf("%d : [%d %d]\n", x, l, r);
		ans += (r-l) * t;
		for(int ix=x+1; ix<=N; ix++) {
			while(l <= N && bit[ix][l] == max(bit[ix][l-1], bit[ix-1][l]) + Nr[ix][l]) l++;
			if(l >= r) break;
			while(r <= N && bit[ix][r] != max(bit[ix][r-1] + t, bit[ix-1][r]) + Nr[ix][r]) r++;
			bit[ix].update(l, t); bit[ix].update(r, -t);
//			printf("%d : [%d %d]\n", ix, l, r);
			ans += (r-l) * t;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
