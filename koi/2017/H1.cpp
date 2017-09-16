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

int gcd(int a, int b) {return b==0?a:gcd(b, a%b);}
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int g = gcd(a, b); a /= g; b /= g;
	if(c % g != 0 || d % g != 0) {
		puts("-1");
		return 0;
	}else c /= g, d /= g;

	if(a == b) {
		printf("%d\n", c+d);
		return 0;
	}
	if(a > b) swap(a, b), swap(c, d);
	if(a == c && b == d) {
		printf("2\n");
		return 0;
	}
	if(c == 0 && d == 0) {
		printf("0\n");
		return 0;
	}
	int na = 0, nb = 0, cnt = 0;
	int minV = INF;
	for(int i=0; i<2*(a+b); i++) {
		if(nb == 0) nb = b, cnt++;
		if(na == c && nb == d) { minV = min(minV, cnt); break; }
		if(na == a) na = 0, cnt++;
		if(na == c && nb == d) { minV = min(minV, cnt); break; }
		if(a - na < nb) nb -= (a-na), na = a, cnt++;
		else na += nb, nb = 0, cnt++;
		if(na == c && nb == d) { minV = min(minV, cnt); break; }
//		printf("%d %d\n", na, nb);
	}
	cnt = 0, na = 0, nb = 0;
	for(int i=0; i<2*(a+b); i++) {
		if(na == 0) na = a, cnt++;
		if(na == c && nb == d) { minV = min(minV, cnt); break; }
		if(nb == b) nb = 0, cnt++;
		if(na == c && nb == d) { minV = min(minV, cnt); break; }
		if(b - nb < na) na -= (b-nb), nb = b, cnt++;
		else nb += na, na = 0, cnt++;
		if(na == c && nb == d) { minV = min(minV, cnt); break; }
	}
	if(minV == INF) minV = -1;
	printf("%d\n", minV);
	return 0;
}
