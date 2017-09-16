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
const pi Ch[4] ={ mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1) };

ll Nr[22];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	int N; cin >> N;
	Nr[2] = 1;
	for(int i=3; i<=20; i++)
		Nr[i] = (i-1) * (Nr[i-1] + Nr[i-2]);
	for(int i=0; i<N; i++)
	{
		int x; scanf("%d", &x);
		printf("%lld\n", Nr[x]);
	}
	return 0;
}