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

const int MAX_N = 2e4 + 100;

int N, Nr[MAX_N], Chk[MAX_N];
int gcd(int a, int b) { return b==0?a:gcd(b, a%b); }
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	cin >> N; for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
	
	int ans = 1;
	for(int i=1; i<=N; i++)
	{
		if(Chk[i] == 1) continue;
		int cnt = 0, now = i;
		while(Chk[now] == 0)
		{
			cnt++;
			Chk[now] = 1;
			now = Nr[now];
		}
		ans = ans / gcd(ans, cnt) * cnt;
	}
	cout << ans;

	return 0;
}