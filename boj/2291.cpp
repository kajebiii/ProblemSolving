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

const int MAX_N = 222, MAX_M = 12;

int N, M; ll K;
ll C[MAX_N][MAX_M];
int Ch[MAX_M];

void getAns(int ix, int p, ll k)
{
	if(ix > M) return;
	for(int i=0; i<=N; i++)
	{
		ll now = C[p-i*(M+1-ix)][M-ix];
		k -= now;
		if(k > 0) continue;
		k += now;
		Ch[ix] = i;
		return getAns(ix+1, p-i*(M+1-ix), k);
	}
}

int main() {
	if(debug) freopen("input.txt", "r", stdin);

	cin >> M >> N >> K;
	N -= M;
	
	C[0][0] = 1;
	for(int i=0; i<=N; i++) C[i][1] = 1;
	for(int j=2; j<=M; j++) for(int i=0; i<=N; i++)
		for(int k=0; k<=i/j; k++)
			C[i][j] += C[i - k*j][j-1];

	getAns(1, N, K);
	for(int i=1; i<=M; i++) printf("%d ", 1 + 
		(Ch[i] = Ch[i-1] + Ch[i]) );
	return 0;
}