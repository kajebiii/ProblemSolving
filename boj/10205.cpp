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

const int MAX_N = 1e2 + 20;
int K; char S[MAX_N];
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	int TC; cin >> TC;
	for(int t=1; t<=TC; t++)
	{
		scanf("%d", &K);
		scanf("%s", S);
		for(int i=0; S[i] != 0; i++) if(S[i] == 'c') K++; else K--;
		printf("Data Set %d:\n", t);
		printf("%d\n", K);
		if(t != TC) puts("");
	}

	return 0;
}