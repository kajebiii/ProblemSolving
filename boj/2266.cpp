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

int N, K, E[555][555];

int main() {
	if(debug) freopen("input.txt", "r", stdin);

	cin >> N >> K;
	for(int i=1; i<=N; i++) E[i][1] = i;
	for(int k=2; k<=K; k++)
		for(int i=1; i<=N; i++)
		{
			E[i][k] = INF;
			for(int j=1; j<=i; j++)
				E[i][k] = min(E[i][k], max(E[j-1][k-1] + 1, E[i-j][k] + 1));
		}
	cout << E[N][K];
	return 0;
}