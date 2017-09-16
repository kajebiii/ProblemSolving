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

char Sc[111];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	int TC; scanf("%d\n", &TC);
	while(TC--)
	{
		fgets(Sc, 111, stdin);
		string S = Sc;
		if(S.length() >= 10 && S.substr(0, 10) == "Simon says")
			cout << S.substr(10, S.length() - 10);
	}
	return 0;
}