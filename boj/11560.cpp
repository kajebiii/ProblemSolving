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

ll Dy[21][444];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	Dy[0][0] = 1;
	for(int i=1; i<=20; i++) for(int j=0; j<=i*(i+1)/2; j++) for(int k=0; k<=min(j, i); k++)
		Dy[i][j] += Dy[i-1][j-k];
	int TC; cin >> TC;
	int A, B;
	while(TC--) scanf("%d%d", &A, &B), printf("%lld\n", Dy[A][B]);
	return 0;
}