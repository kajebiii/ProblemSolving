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

map<int, int> M;
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	int TC; cin >> TC;
	while(TC--)
	{
		int N; scanf("%d", &N);
		M.clear();
		for(int i=0, x; i<N; i++)
		{
			scanf("%d", &x);
			if(M.count(x) == 0) M[x] = 1;
			else M[x]++;
		}
		int ans = -1, ansN = -1;
		for(auto x : M)
			if(ans < x.se)
				ans = x.se, ansN = x.fi;
		cout << ansN << endl;
	}

	return 0;
}