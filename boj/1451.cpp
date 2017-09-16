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

const int MAX_N = 1e2 + 20;

int N, M, Nr[MAX_N][MAX_N];
int Sum[MAX_N][MAX_N], Ch[MAX_N][MAX_N];

ll getAns(ll &result)
{
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
		Sum[i][j] = Sum[i-1][j] + Sum[i][j-1] - Sum[i-1][j-1] + Nr[i][j];
	for(int i=1; i<N; i++) for(int j=1; j<M; j++)
	{
		int a = Sum[i][j], b = Sum[N][j] - Sum[i][j];
		int c = Sum[N][M] - Sum[N][j];
		result = max(result, 1ll * a * b * c);
	}
	for(int i=1; i<N-1; i++) for(int j=i+1; j<N; j++)
	{
		int a = Sum[i][M], b = Sum[j][M] - Sum[i][M];
		int c = Sum[N][M] - Sum[j][M];
		result = max(result, 1ll * a * b * c);
	}

	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
		Ch[j][N+1-i] = Nr[i][j];
	swap(N, M);
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
		Nr[i][j] = Ch[i][j];

	return result;
}

int main() {
	if(debug) freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
		scanf("%1d", &Nr[i][j]);
	ll ans = 0;
	getAns(ans);
	getAns(ans);
	getAns(ans);
	getAns(ans);
	cout << ans;
	return 0;
}