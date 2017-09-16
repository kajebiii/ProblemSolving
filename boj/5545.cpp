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

int N, A, B, C, D[111];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N >> A >> B >> C;
	for(int i=0; i<N; i++) scanf("%d", &D[i]);
	sort(D, D+N); reverse(D, D+N);

	for(int i=0; i<N; i++)
		if(C * B < D[i] * A) C += D[i], A += B;
	
	printf("%d\n", C / A);
	return 0;
}