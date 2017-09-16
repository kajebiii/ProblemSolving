// =====================================================================================
//
//       Filename:  3023.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 18:59:14
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
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

char Map[111][111];
int main() {
	int R, C; cin >> R >> C;
	for(int i=0; i<R; i++) scanf("%s", Map[i]);
	for(int i=0; i<R; i++) for(int j=0; j<C; j++) Map[i][2*C-1-j] = Map[i][j];
	for(int j=0; j<2*C; j++) for(int i=0; i<R; i++) Map[2*R-1-i][j] = Map[i][j];
	int X, Y; cin >> X >> Y; Map[X-1][Y-1] = '#' + '.' - Map[X-1][Y-1];
	for(int i=0; i<2*R; i++) puts(Map[i]);
	return 0;
}










