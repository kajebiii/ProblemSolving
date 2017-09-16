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

const int MAX_P = 1 << 19;
const int MAX_N = 5e5 + 100;

int N, T[MAX_P + MAX_N], Nr[MAX_N], P;
void U(int v) { T[v]++; while(v/=2) { T[v] = T[v*2] + T[v*2+1]; } }
int G(int a, int b) { return a>b?0:G((a+1)/2, (b-1)/2) + (a%2==1?T[a]:0) + (b%2==0?T[b]:0); }
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	cin >> N;
	for(P=1; P<N; P<<=1);
	for(int i=0; i<N; i++) scanf("%d", &Nr[i]), T[i] = Nr[i];
	sort(T, T+N);
	int SN = unique(T, T+N) - T;
	for(int i=0; i<N; i++) Nr[i] = lower_bound(T, T+SN, Nr[i]) - T;
	for(int i=0; i<=P; i++) T[i] = 0;

	ll ans = 0;
	for(int i=N-1; i>=0; i--)
	{
		ans += (ll)G(P, P+Nr[i]-1);
		U(P+Nr[i]);
	}
	cout << ans;
	return 0;
}