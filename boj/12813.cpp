// =====================================================================================
//
//       Filename:  12813.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/22/2016 16:10:38
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
#include <assert.h>

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
const int MAX_N = 1e5 + 100;

int Nr[2][MAX_N];
char C[2][MAX_N];
char Ans[MAX_N];
int main() {
	for(int i=0; i<2; i++) scanf("%s", C[i]);
	int N = (int)strlen(C[0]);
	for(int i=0; i<2; i++) for(int j=0; j<N; j++) Nr[i][j] = C[i][j] - '0';
	for(int i=0; i<N; i++) Ans[i] = (Nr[0][i] & Nr[1][i]) + '0'; puts(Ans);
	for(int i=0; i<N; i++) Ans[i] = (Nr[0][i] | Nr[1][i]) + '0'; puts(Ans);
	for(int i=0; i<N; i++) Ans[i] = (Nr[0][i] ^ Nr[1][i]) + '0'; puts(Ans);
	for(int i=0; i<N; i++) Ans[i] = (1-Nr[0][i]) + '0'; puts(Ans);
	for(int i=0; i<N; i++) Ans[i] = (1-Nr[1][i]) + '0'; puts(Ans);
	return 0;
}










