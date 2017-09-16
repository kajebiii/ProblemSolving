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

const int MAX_N = 5e6 + 500;

int N, L, Nr[MAX_N];
deque<int> Q;

int main() {
	if(debug) freopen("input.txt", "r", stdin);

	cin >> N >> L;
	for(int i=0; i<N; i++)
	{
		scanf("%d", &Nr[i]);
		while(!Q.empty() && Q.front() <= i - L) Q.pop_front();
		while(!Q.empty() && Nr[Q.back()] >= Nr[i]) Q.pop_back();
		Q.push_back(i);
		printf("%d ", Nr[Q.front()]);
	}

	return 0;
}