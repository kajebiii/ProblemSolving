// =====================================================================================
//
//       Filename:  2342.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/12/2016 18:51:29
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

int Move[5][5];
int Dy[2][5][5];
int main() {
	for(int i=0; i<5; i++) for(int j=0; j<5; j++) Dy[0][i][j] = INF / 2;
	Dy[0][0][0] = 0;
	int t = 1, ans = -1;
	for(int i=1; i<=4; i++) Move[0][i] = Move[i][0] = 2;
	for(int i=0; i<4; i++) Move[i+1][(i+1)%4+1] = Move[(i+1)%4+1][i+1] = 3;
	for(int i=0; i<4; i++) Move[i+1][(i+2)%4+1] = 4;
	for(int i=1; i<=4; i++) Move[i][i] = 1;
	while(1)
	{
		int now; scanf("%d", &now);
		if(now == 0) {printf("%d", ans); break;}
		ans = INF;
		for(int i=0; i<5; i++) for(int j=0; j<5; j++) Dy[t%2][i][j] = INF / 2;
		for(int i=0; i<5; i++) for(int j=0; j<5; j++)
		{
			if(i == j) continue;
			if(i != now && j != now) continue;
			if(i == now) for(int x=0; x<5; x++)
				Dy[t%2][i][j] = min(Dy[t%2][i][j], Dy[1-t%2][x][j] + Move[x][i]);
			if(j == now) for(int x=0; x<5; x++)
				Dy[t%2][i][j] = min(Dy[t%2][i][j], Dy[1-t%2][i][x] + Move[x][j]);
			ans = min(ans, Dy[t%2][i][j]);
		}
		t++;
	}
	return 0;
}










