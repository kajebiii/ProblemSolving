#include <stdio.h>
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

int N, M, Nr[111], Need[111];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for(int o=0; o<N; o++)
	{
		int p, l; scanf("%d%d", &p, &l);
		for(int i=0; i<p; i++) scanf("%d", &Nr[i]);
		sort(Nr, Nr+p);
		if(l > p) Need[o] = 1;
		else Need[o] = Nr[p-l];
	}
	sort(Need, Need+N);
	int ans = 0;
	while(ans < N && M - Need[ans] >= 0) M -= Need[ans++];
	cout << ans;
	return 0;
}