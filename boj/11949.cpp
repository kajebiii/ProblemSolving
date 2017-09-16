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

const int MAX_N = 111;

int N, M, A[MAX_N];

int main() {
	if(debug) freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for(int i=1; i<=N; i++) scanf("%d", &A[i]);
	for(int p=1; p<=M; p++)
		for(int i=2; i<=N; i++)
			if(A[i-1] % p > A[i] % p)
				swap(A[i-1], A[i]);
	
	for(int i=1; i<=N; i++) printf("%d\n", A[i]);
	return 0;
}