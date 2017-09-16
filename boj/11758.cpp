// =====================================================================================
//
//       Filename:  11758.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 21:22:58
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

int main() {
	int A[3][2]; for(int i=0; i<3; i++) for(int j=0; j<2; j++) cin >> A[i][j];
	int B[2][2]; for(int i=0; i<2; i++) for(int j=0; j<2; j++)
		B[i][j] = A[i+1][j] - A[i][j];
	int d = B[0][0] * B[1][1] - B[0][1] * B[1][0];
	if(d < 0) puts("-1");
	else if(d == 0) puts("0");
	else puts("1");
	return 0;
}










