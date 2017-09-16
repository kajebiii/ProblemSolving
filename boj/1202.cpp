#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string.h>
#include <string>
#include <queue>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <math.h>
#include <assert.h>
#include <memory.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define ft first
#define sd second
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) { return mp(x.ft + y.ft, x.sd + y.sd); }

const int INF = 0x7fffffff;
const pi Ch[4] = { mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1) };
const int MOD = 1e9 + 7;
const int MAX_N = 3e5 + 100, MAX_K = 3e5 + 100;

int N, K;
pi Nr[MAX_N];

int main()
{
	cin >> N >> K;
	for(int i=0; i<N; i++)
		scanf("%d %d", &Nr[i].sd, &Nr[i].ft);
	sort(Nr, Nr+N);

	multiset<int> S;
	for(int i=0, x; i<K; i++)
	{
		scanf("%d", &x);
		S.insert(x);
	}
	
	ll ans = 0;
	for(int i=N-1; i>=0; i--)
	{
		if(S.empty() == true) break;
		auto it = S.lower_bound(Nr[i].sd);
		if(it == S.end()) continue;
		ans += Nr[i].ft;
		S.erase(it);
	}
	cout << ans;
	return 0;
}
