// =====================================================================================
//
//       Filename:  2422.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/12/2016 18:46:43
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

bool doNot[222][222];
int main() {
	int N, M; cin >> N >> M;
	while(M--)
	{
		int x, y; scanf("%d%d", &x, &y);
		doNot[x][y] = doNot[y][x] = true;
	}
	
	int ans = 0;
	for(int i=1; i<=N; i++) for(int j=i+1; j<=N; j++) for(int k=j+1; k<=N; k++)
		if(!doNot[i][j] && !doNot[j][k] && !doNot[k][i]) ans++;
	cout << ans;
	return 0;
}










