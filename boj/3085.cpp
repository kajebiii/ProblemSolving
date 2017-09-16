// =====================================================================================
//
//       Filename:  3085.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/15/2016 08:45:41
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

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
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

char Map[55][55]; int N;
int findMax()
{
	int ans = 0;
	for(int i=0; i<N; i++)
		for(int j=0, c0 = 0, c1 = 0; j<N; j++)
		{
			if(j == 0 || Map[i][j-1] != Map[i][j])
				c0 = 1;
			else
				c0++;
			if(j == 0 || Map[j-1][i] != Map[j][i])
				c1 = 1;
			else
				c1++;
			ans = max(ans, max(c0, c1));
		}
	return ans;
}
int main() {
	cin >> N; for(int i=0; i<N; i++) scanf("%s", Map[i]);

	int ans = 0;
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) for(int k=0; k<4; k++)
	{
		int x = i + Ch[k].fi, y = j + Ch[k].se;
		if(x < 0 || y < 0 || x >= N || y >= N) continue;
		if(Map[i][j] == Map[x][y]) continue;
		swap(Map[i][j], Map[x][y]);
		ans = max(ans, findMax());
		swap(Map[i][j], Map[x][y]);
	}
	cout << ans;
	return 0;
}










