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

int N, Nr[11111];
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	int TC; cin >> TC;
	
	while(TC--)
	{
		scanf("%d", &N);
		for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
		int sum = accumulate(Nr, Nr+N, 0);
		int ans = sum;
		int now = 0;
		for(int i=0; i<N; i++)
		{
			now += Nr[i];
			if(now > sum / 2) break;
			if(sum % now != 0) continue;
			int j = i+1;
			int cnt = 0;
			bool flag = true;
			for(; j<N; j++)
			{
				cnt += Nr[j];
				if(cnt > now) { flag = false; break; }
				else if(cnt == now) cnt = 0;
			}
			if(cnt != 0) flag = false;
			if(flag) { ans = now; break; }
		}
		printf("%d\n", ans);
	}
	return 0;
}