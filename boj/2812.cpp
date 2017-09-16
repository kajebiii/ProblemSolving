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

const int MAX_N = 5e5 + 100;

int T[MAX_N*4][2], P, N, K;

pi getMin(int a, int b)
{
	int result = -1;
	int index = INF;
	int aa = a, bb = b;
	while(a<=b)
	{
		if(a%2  ) result = max(T[a++][0], result);
		if(1-b%2) result = max(T[b--][0], result);
		a/=2; b/=2;
	}
	a = aa; b = bb;
	while(a<=b)
	{
		if(a%2  ) index = min(index, (result==T[a][0]?T[a][1]:INF)), ++a;
		if(1-b%2) index = min(index, (result==T[b][0]?T[b][1]:INF)), --b;
		a/=2; b/=2;
	}
	return mp(result, index);
}

int main() {
	if(debug) freopen("input.txt", "r", stdin);

	cin >> N >> K;

	for(P=1; P<N; P<<=1);

	for(int i=0; i<N; i++) scanf("%1d", &T[P+i][0]), T[P+i][1] = i;

	for(int i=P-1; i>=1; i--)
	{
		T[i][0] = max(T[i*2][0], T[i*2+1][0]);
		if(T[i*2][0] == T[i][0]) T[i][1] = T[i*2][1];
		else T[i][1] = T[i*2+1][1];
	}

	int left = 0, right = N-1;
	for(int i=N-K; i>=1; i--)
	{
		pi get = getMin(left + P, right - i + 1 + P);
		printf("%d", get.fi);
		left = get.se + 1;
	}
	

	return 0;
}