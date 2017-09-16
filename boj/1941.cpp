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

char Map[5][5];
int Chk[5][5];

int main() {
	if(debug) freopen("input.txt", "r", stdin);
	for(int i=0; i<5; i++) for(int j=0; j<5; j++)
		scanf("%c\n", &Map[i][j]);

	int choose[25] ={ 0 };
	for(int i=25-7; i<25; i++) choose[i] = 1;
	
	int ans = 0;
	do
	{
		int cnt = 0;
		for(int i=0; i<5; i++) for(int j=0; j<5; j++)
			if(Chk[i][j] = choose[i*5+j])
				cnt += Map[i][j] == 'S';
		int grp = 0;
		for(int i=0; i<5; i++) for(int j=0; j<5; j++)
		{
			if(Chk[i][j] != 1) continue;
			grp++;
			if(grp > 1) break;

			queue<int> Q;
			Q.push(i*5+j);
			while(!Q.empty())
			{
				int now = Q.front(); Q.pop();
				for(int k : vector<int>({ -5, -1, 1, 5 }))
				{
					int next = now + k;
					if(now % 5 == 4 && k == 1) continue;
					if(now % 5 == 0 && k == -1) continue;
					if(next < 0 || next >= 25) continue;
					int x = next/5, y = next%5;
					if(Chk[x][y] != 1) continue;
					Chk[x][y] = 2;
					Q.push(next);
				}
			}
		}
		if(grp == 1 && cnt >= 4) ans++;
	} while(next_permutation(choose, choose+25));
	cout << ans;
	return 0;
}