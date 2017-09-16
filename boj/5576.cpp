// =====================================================================================
//
//       Filename:  5576.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 00:34:49
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
	int A[2][10];
	for(int i=0; i<2; i++) for(int j=0; j<10; j++) scanf("%d", &A[i][j]);
	for(int i=0; i<2; i++) sort(A[i], A[i]+10);
	cout << accumulate(A[0]+7, A[0]+10, 0) << " " <<accumulate(A[1]+7, A[1]+10, 0);
	return 0;
}










