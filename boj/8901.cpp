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

int Nr[6];
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	int TC; cin >> TC;

	while(TC--)
	{
		for(int i=0; i<6; i++) scanf("%d", &Nr[i]);

		int ans = 0;
		for(int i=0; i<=Nr[0]; i++) for(int j=0; j+i<=Nr[0]; j++)
		{
			if(i > Nr[1]) break;
			if(j > Nr[2]) break;
			ans = max(ans, i*Nr[3] + j*Nr[5] + min(Nr[1]-i, Nr[2]-j) * Nr[4]);
		}
		printf("%d\n", ans);
	}

	return 0;
}