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
const int MAX_N = 15e2 + 100;

int N, Nr[MAX_N][MAX_N];
int Dy[MAX_N][MAX_N];

int main() {
	if(debug) freopen("input.txt", "r", stdin);

	cin >> N;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) scanf("%d", &Nr[i][j]);
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) Dy[i][j] = INF;
	Dy[2][1] = Nr[1][2];

	for(int i=3; i<=N; i++)
	{
		for(int j=1; j<i-1; j++) Dy[i][j] = min(Dy[i][j], Dy[i-1][j] + Nr[i-1][i]);
		for(int k=1; k<i-1; k++) Dy[i][i-1] = min(Dy[i][i-1], Dy[i-1][k] + Nr[k][i]);
	}
	int ans = INF;
	for(int i=1; i<N; i++) ans = min(ans, Dy[N][i]);

	cout << ans;
	return 0;
}