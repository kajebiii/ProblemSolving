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

map<int, string> M;
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	int TC; cin >> TC;

	M[1] = "Yakk"; M[2] = "Doh"; M[3] = "Seh";
	M[4] = "Ghar"; M[5] = "Bang"; M[6] = "Sheesh";
	M[11] = "Habb Yakk"; M[12] = "Dobara"; M[13] = "Dousa";
	M[14] = "Dorgy"; M[15] = "Dabash"; M[16] = "Dosh";
	for(int t=1; t<=TC; t++)
	{
		int a[2];
		scanf("%d%d", &a[0], &a[1]);
		if(a[0] < a[1]) swap(a[0], a[1]);

		printf("Case %d:", t);
		if(a[0] == 6 && a[1] == 5) cout << " Sheesh Beesh" << endl;
		else if(a[0] == a[1]) cout << " " << M[10 + a[0]] << endl;
		else cout << " " << M[a[0]] << " " << M[a[1]] << endl;
	}
	return 0;
}