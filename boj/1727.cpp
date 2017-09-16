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

int N[2], Nr[1111][1111];
vector<int> V[2];

int main() {
	if(debug) freopen("input.txt", "r", stdin);
	for(int i=0; i<2; i++) scanf("%d", &N[i]);
	for(int i=0; i<2; i++) for(int j=0; j<N[i]; j++)
	{
		int x; scanf("%d", &x);
		V[i].pb(x);
	}
	for(int i=0; i<2; i++) sort(V[i].begin(), V[i].end());
	if(N[0] > N[1]) { swap(N[0], N[1]); swap(V[0], V[1]); }
	for(int i=0; i<N[1]; i++) Nr[0][i] = min(abs(V[0][0] - V[1][i]), i?Nr[0][i-1]:INF);
	for(int i=1; i<N[0]; i++)
	{
		Nr[i][i] = Nr[i-1][i-1] + abs(V[0][i] - V[1][i]);

		for(int j=i+1; j<N[1]; j++)
			Nr[i][j] = min(Nr[i-1][j-1] + abs(V[0][i] - V[1][j]), Nr[i][j-1]);
		
	}

	int ans = INF;
	for(int i=N[0]-1; i<N[1]; i++)
		ans = min(ans, Nr[N[0]-1][i]);
	
	printf("%d", ans);
	return 0;
}