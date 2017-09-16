// =====================================================================================
//
//       Filename:  3054.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/14/2016 03:52:05
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
const pi Ch[8] = {mp(-2, 0), mp(0, -2), mp(2, 0), mp(0, 2), mp(1, 1), mp(1, -1), mp(-1, 1), mp(-1, -1)};

char Map[5][99];
int main() {
	string S; cin >> S; int N = S.length();
	for(int i=0; i<5; i++) for(int j=0; j<N*4+1; j++) Map[i][j] = '.';
	for(int i=0; i<N; i++) for(int k=0; k<8; k++)
		Map[2+Ch[k].fi][i*4+2+Ch[k].se] = '#';
	for(int i=2; i<N; i+=3) for(int k=0; k<8; k++)
		Map[2+Ch[k].fi][i*4+2+Ch[k].se] = '*';
	for(int i=0; i<N; i++) Map[2][i*4+2] = S[i];
	for(int i=0; i<5; i++) puts(Map[i]);
	return 0;
}










