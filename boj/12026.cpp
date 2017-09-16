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

const int MAX_N = 1e3 + 100;

int N, Dy[MAX_N]; char S[MAX_N];
map<char, char> M;
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	M['O'] = 'B'; M['J'] = 'O'; M['B'] = 'J';
	cin >> N; scanf("%s", S);
	for(int i=1; i<N; i++) Dy[i] = INF;
	
	for(int i=1; i<=N; i++)
	{
		for(int j=0; j<i; j++)
			if(M[S[i]] == S[j]) if(Dy[j] != INF)
				Dy[i] = min(Dy[i], Dy[j] + (i-j) * (i-j));
	}
	int ans = Dy[N-1];
	printf("%d", ans==INF?-1:ans);
	return 0;
}