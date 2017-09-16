// =====================================================================================
//
//       Filename:  11536.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/23/2016 09:49:25
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

int N; string V[22];
int main() {
	cin >> N; for(int i=0; i<N; i++) cin >> V[i];
	if(next_permutation(V, V+N) == false) {puts("DECREASING"); return 0;}
	prev_permutation(V, V+N);
	if(prev_permutation(V, V+N) == false) {puts("INCREASING"); return 0;}
	puts("NEITHER");
	return 0;
}










