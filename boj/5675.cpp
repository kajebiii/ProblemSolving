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

int Chk[333];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	
	int h = 0, m = 0;
	for(int i=1; i<=720; i++)
	{
		m += 6;
		if(i % 12 == 0) h += 6;
		int diff = (m - h) % 360;
		if(diff > 180) Chk[360 - diff] = 1;
		else Chk[diff] = 1;
	}
	int x; while(scanf("%d", &x) == 1)
		printf("%c\n", Chk[x]==1?'Y':'N');
	return 0;
}