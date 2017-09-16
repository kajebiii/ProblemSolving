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

int Nr[MAX_N][MAX_N];
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	int N, M;
	while(scanf("%d%d", &N, &M) == 2)
	{
		if(N == 0 && M == 0) break;
		for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) scanf("%d", &Nr[i][j]);
		for(int j=1; j<=M; j++) for(int i=1; i<=N; i++)
			if(Nr[i][j] == 1) Nr[i][j] = Nr[i-1][j] + 1;

		int ans = 0;
		for(int i=1; i<=N; i++)
		{
			stack<int> S; S.push(0);
			int j = 1;
			Nr[i][M+1] = 0;
			while(j <= M+1)
				if(Nr[i][S.top()] <= Nr[i][j])
					S.push(j++);
				else
				{
					int right = j-1;
					int height = Nr[i][S.top()]; S.pop();
					int left = S.top() + 1;
					ans = max(ans, min(height, (right - left + 1)) );
				}
		}
		printf("%d\n", ans);
	}

	return 0;
}