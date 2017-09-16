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

bool notP[2000000]; int PN = 2000000;
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	notP[1] = true; for(int i=2; i<PN; i++) if(notP[i] == false) for(int j=i*2; j<PN; j+=i) notP[j] = true;
	int TC; cin >> TC;
	while(TC--)
	{
		int x; scanf("%d", &x);
		if(notP[x] == false) { puts("0"); continue; }
		int l = -1, r = -1;
		for(int i=x-1; i>=2; i--) if(notP[i] == false) { l = i; break; }
		for(int i=x+1; ; i++)     if(notP[i] == false) { r = i; break; }
		if(l == -1 || r == -1) { puts("0"); continue; }
		else printf("%d\n", r - l);
	}
	return 0;
}