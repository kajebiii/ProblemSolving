// =====================================================================================
//
//       Filename:  12759.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 16:24:07
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

int Chk[4][4];
int main() {
	int start; cin >> start;
	int now = start;
	bool finish = false;
	for(int i=0; i<9; i++)
	{
		int x, y; cin >> x >> y;
		Chk[x][y] = now;

		for(int i=1; i<=3; i++)
		{
			bool line = true;
			for(int j=1; j<=3; j++) if(Chk[i][j] != now) line = false;
			if(line) {finish = true; break;}
			line = true;
			for(int j=1; j<=3; j++) if(Chk[j][i] != now) line = false;
			if(line) {finish = true; break;}
		}
		bool line = true;
		for(int i=1; i<=3; i++) if(Chk[i][i] != now) line = false;
		if(line) finish = true;
		line = true;
		for(int i=1; i<=3; i++) if(Chk[i][4-i] != now) line = false;
		if(line) finish = true;
		if(finish) {printf("%d", now); break;}
		now = 3 - now;
	}
	if(finish == false) printf("0");
	return 0;
}










