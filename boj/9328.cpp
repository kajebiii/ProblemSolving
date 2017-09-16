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

int N, M, Chk[222], Go[111][111];
char Map[111][111], Key[111];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	
	int TC; cin >> TC;
	while(TC--)
	{
		scanf("%d%d", &N, &M);
		for(int i=1; i<=N; i++) scanf("%s", Map[i]+1);
		N += 2; M += 2;
		for(int i=0; i<N; i++) Map[i][0] = Map[i][M-1] = '.';
		for(int i=0; i<M; i++) Map[0][i] = Map[N-1][i] = '.';
		
		for(int i=0; i<26; i++) Chk['A' + i] = 0;
		scanf("%s", Key);
		for(int i=0; Key[i] != 0; i++)
		{
			if(Key[i] == '0') break;
			Chk[Key[i] - 'a' + 'A'] = 1;
		}

		int ans = 0;
		while(1)
		{
			for(int i=0; i<N; i++) for(int j=0; j<M; j++)
				if(Chk[Map[i][j]] == 1)
					Map[i][j] = '.';
			for(int i=0; i<N; i++) for(int j=0; j<M; j++)
				Go[i][j] = 0;

			queue<pi> Q; Q.push(mp(0, 0));
			Go[0][0] = 1;

			bool change = false;
			while(!Q.empty())
			{
				pi now = Q.front(); Q.pop();
				int x, y; tie(x, y) = now;
				if(Map[x][y] >= 'a' && Map[x][y] <= 'z')
				{
					Chk[Map[x][y] - 'a' + 'A'] = 1;
					Map[x][y] = '.';
					change = true;
				}
				if(Map[x][y] == '$')
				{
					ans = ans + 1;
					Map[x][y] = '.';
				}
				for(int k=0; k<4; k++)
				{
					pi next = now + Ch[k];
					int x, y; tie(x, y) = next;
					if(x < 0 || y < 0 || x >= N || y >= M) continue;
					if(Map[x][y] == '*') continue;
					if(Map[x][y] >= 'A' && Map[x][y] <= 'Z') continue;
					if(Go[x][y] == 1) continue;
					Q.push(mp(x, y));
					Go[x][y] = 1;
				}
			}
			if(change == false) break;
		}
		printf("%d\n", ans);
	}
	return 0;
}