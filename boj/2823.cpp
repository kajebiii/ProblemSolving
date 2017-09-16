// =====================================================================================
//
//       Filename:  2823.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/17/2016 14:50:08
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

int R, C;
char Map[22][22];
int main() {
	cin >> R >> C; for(int i=1; i<=R; i++) scanf("%s", Map[i] + 1);
	for(int i=1; i<=R; i++) Map[i][0] = Map[i][C+1] = 'X';
	for(int i=1; i<=C; i++) Map[0][i] = Map[R+1][i] = 'X';
	bool flag = true;
	for(int i=1; i<=R; i++) for(int j=1; j<=C; j++)
	{
		if(Map[i][j] == 'X') continue;
		int cnt = 0;
		for(int k=0; k<4; k++)
			if(Map[i+Ch[k].fi][j+Ch[k].se] == 'X')
				cnt++;
		if(cnt >= 3) flag = false;
	}
	if(flag) printf("0");
	else printf("1");
	return 0;
}










