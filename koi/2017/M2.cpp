#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, int> pli;
typedef pair<ll, ll> pll; typedef pair<ll, pi> plp;
typedef tuple<int, int, int> ti; typedef tuple<ll, int, int> tli;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 2e6 + 100;

int N; pi Nr[MAX_N];
int main() {
	cin >> N;
	int ix = -1;
	for(int i=0; i<N; i++) {
		int x, y; scanf("%d%d", &x, &y);
		Nr[i] = Nr[i+N] = pi(x, y);
		if(y < 0) ix = i;
	}
	vector<pi> list; int mul = 1;
	for(int p=0; p<N; p++) {
		int i = ix+p, j = ix+p+1;
		if((Nr[i].two < 0) ^ (Nr[j].two < 0)) {
			list.push_back(pi(Nr[i].one, mul));
			if(mul == -1 && list[SZ(list)-2].one > list.back().one)
				swap(list[SZ(list)-2].one, list.back().one);
			mul *= -1;
		}
	}
	sort(ALL(list));
	int bCnt = 0, sCnt = 0;
	for(int i=0, lv=0; i<SZ(list); i++) {
		lv += list[i].two;
		if(list[i].two == 1 && lv == 1) bCnt++;
		if(i && list[i-1].two == 1 && list[i].two == -1) sCnt++;
	}
	printf("%d %d\n", bCnt, sCnt);
	return 0;
}