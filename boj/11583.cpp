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
const int MAX_N = 1e5 + 100;

int N, K, Nr[MAX_N][2], Dy[MAX_N][2];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	int TC; cin >> TC;
	while(TC--)
	{
		scanf("%d%d", &N, &K);
		for(int i=1; i<=N; i++)
		{
			int x; scanf("%d", &x);
			Nr[i][0] = Nr[i][1] = 0;
			while(x % 2 == 0) Nr[i][0]++, x/=2;
			while(x % 5 == 0) Nr[i][1]++, x/=5;
		}
		Dy[1][0] = Nr[1][0]; Dy[1][1] = Nr[1][1];
		for(int i=2; i<=N; i++)
		{
			Dy[i][0] = Dy[i][1] = INF;
			for(int j=i-1; j>=max(i-K, 1); j--)
				for(int k=0; k<2; k++)
					Dy[i][k] = min(Dy[i][k], Dy[j][k] + Nr[i][k]);
		}
		printf("%d\n", min(Dy[N][0], Dy[N][1]));
	}
	return 0;
}