#include <stdio.h>
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
const int MAX_N = 1e5 + 100;

int N, K, Nr[MAX_N], Ch[MAX_N];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N >> K;
	for(int i=0; i<N; i++) scanf("%d", &Nr[i]);

	int ans = 0, cnt = 0;
	for(int i=0; i<N; i++)
	{
		cnt += Ch[i];
		Nr[i] = (Nr[i] + cnt) % 2;
		if(i <= N-K && Nr[i] == 1) Ch[i+K] = -1, ans++, cnt++, Nr[i] = 0;
	}
	bool isCan = true;
	for(int i=0; i<N; i++) if(Nr[i] == 1) isCan = false;
	if(isCan == false) puts("Insomnia");
	else printf("%d\n", ans);
	return 0;
}