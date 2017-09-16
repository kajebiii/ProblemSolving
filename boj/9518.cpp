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
const pi Ch[8] ={ mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1), mp(-1, -1), mp(1, 1), mp(-1, 1), mp(1, -1) };

int N, M; char S[55][55];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N >> M; 
	for(int i=1; i<=N; i++) scanf("%s", S[i] + 1);
	int ans = 0, plus = 0;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
	{
		pi now = mp(i, j);
		int cnt = 0;
		for(int k=0; k<8; k++)
		{
			pi next = now + Ch[k];
			if(S[next.fi][next.se] == 'o') cnt++;
		}
		if(S[i][j] == '.') ans = max(ans, cnt);
		else plus += cnt;
	}
	cout << ans + plus / 2;
	return 0;
}