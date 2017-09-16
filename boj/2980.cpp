#include <stdio.h>
#include <functional>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string.h>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) { return mp(x.fi+y.fi, x.se+y.se); }

const int INF = 0x7fffffff;
const pi Ch[4] ={ mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1) };

const int MAX_N = 1e2 + 50;

int N, Length;
struct LIGHT { 
	int l, r, g; 
	LIGHT() :l(0), r(0), g(0) {}
	LIGHT(int L, int R, int G) : l(L), r(R), g(G) {}
	const bool operator<(const LIGHT &o) const
	{
		return l < o.l;
	}
}L[MAX_N];

int main() {
	if(debug) freopen("input.txt", "r", stdin);

	cin >> N >> Length;
	for(int i=0; i<N; i++) scanf("%d%d%d", &L[i].l, &L[i].r, &L[i].g);
	L[N++] = LIGHT(Length, 0, 1);
	sort(L, L+N);
	int T = 0, Now = 0;
	for(int i=0; i<N; i++)
	{
		T += L[i].l - Now;
		Now = L[i].l;
		int temp = T % (L[i].r + L[i].g);
		if(temp >= L[i].r) continue;
		else T += L[i].r - temp;
	}
	cout << T;
	return 0;
}