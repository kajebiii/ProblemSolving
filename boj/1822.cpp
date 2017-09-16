// =====================================================================================
//
//       Filename:  1822.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/11/2016 00:13:17
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
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int main() {	
	int N[2]; cin >> N[0] >> N[1];
	set<int> S[2];
	for(int k=0; k<2; k++) for(int x, i=0; i<N[k]; i++)
		scanf("%d", &x), S[k].insert(x);
	int cnt = 0;
	for(int x : S[0])
		if(S[1].count(x) == 0) cnt++;
	printf("%d\n", cnt);
	for(int x : S[0])
		if(S[1].count(x) == 0) printf("%d ", x);
	return 0;
}










