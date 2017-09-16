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
const pi Ch[2] ={ mp(-1, 0), mp(0, -1) };

int N, M, K;
ll Dy[111][111];
set<ll> S;
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	
	cin >> N >> M >> K;
	for(int k=0; k<K; k++)
	{
		int A[4];
		for(int i=0; i<4; i++) scanf("%d", &A[i]);
		ll now = 0;
		for(int i=0; i<4; i++) now *= 101, now += A[i];
		S.insert(now);
		now = 0;
		for(int i=0; i<2; i++) swap(A[i], A[i+2]);
		for(int i=0; i<4; i++) now *= 101, now += A[i];
		S.insert(now);
	}

	Dy[0][0] = 1;
	for(int i=0; i<=N; i++) for(int j=0; j<=M; j++)
	{
		for(int k=0; k<2; k++)
		{
			int A[4] ={ i+Ch[k].fi, j+Ch[k].se, i, j };
			if(A[0] < 0 || A[1] < 0) continue;
			ll now = 0;
			for(int i=0; i<4; i++) now *= 101, now += A[i];
			if(S.count(now) == 1) continue;
			Dy[i][j] += Dy[A[0]][A[1]];
		}
	}

	cout << Dy[N][M];
	return 0;
}