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

const int MAX_N = 1e5 + 100;

int N, In[MAX_N], Post[MAX_N], Find[MAX_N];

void find(int a, int b, int x, int y)
{
	if(a > b || x > y) return;
	int ix = Find[Post[y]];
	int c1 = ix - a, c2 = b - ix;
	printf("%d ", Post[y]);
	find(a, a+c1-1, x, x+c1-1);
	find(ix+1, b, y-1-c2+1, y-1);
}
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N;
	for(int i=0; i<N; i++) scanf("%d", &In[i]), Find[In[i]] = i;
	for(int i=0; i<N; i++) scanf("%d", &Post[i]);
	find(0, N-1, 0, N-1);
	return 0;
}