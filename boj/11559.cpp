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

char Map[12][7];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	for(int i=11; i>=0; i--) scanf("%s\n", Map[i]);

	int ans = -1;
	while(1)
	{
		bool change = false;
		for(int i=0; i<12; i++) for(int j=0; j<6; j++)
		{
			if(Map[i][j] == '.') continue;
			queue<pi> Q; set<pi> S;
			Q.push(mp(i, j)); S.insert(mp(i, j));
			while(!Q.empty())
			{
				pi now = Q.front(); Q.pop();
				for(int k=0; k<4; k++)
				{
					pi next = now + Ch[k];
					if(next.fi < 0 || next.se < 0 || next.fi >= 12 || next.se >= 6) continue;
					if(Map[next.fi][next.se] != Map[now.fi][now.se]) continue;
					if(S.count(next) > 0) continue;
					S.insert(next);
					Q.push(next);
				}
			}
			if(S.size() >= 4) change = true;
			if(S.size() >= 4) for(pi now : S) Map[now.fi][now.se] = '.';
		}
		for(int j=0; j<6; j++) for(int i=0, cnt=0; i<12; i++)
			if(Map[i][j] != '.')
			{
				Map[cnt][j] = Map[i][j];
				if(cnt != i) Map[i][j] = '.';
				cnt++;
			}
		ans++;
		if(change == false) break;
	}
	printf("%d\n", ans);
	return 0;
}