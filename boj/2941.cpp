// =====================================================================================
//
//       Filename:  2941.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/15/2016 16:29:05
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

int main() {
	string S; cin >> S;
	int ix = 0, cnt = 0;
	while(ix < S.length())
	{
		cnt++;
		if(S.substr(ix, 2) == "c=") {ix += 2; continue;}
		if(S.substr(ix, 2) == "c-") {ix += 2; continue;}
		if(S.substr(ix, 3) == "dz=") {ix += 3; continue;}
		if(S.substr(ix, 2) == "d-") {ix += 2; continue;}
		if(S.substr(ix, 2) == "lj") {ix += 2; continue;}
		if(S.substr(ix, 2) == "nj") {ix += 2; continue;}
		if(S.substr(ix, 2) == "s=") {ix += 2; continue;}
		if(S.substr(ix, 2) == "z=") {ix += 2; continue;}
		ix++;
	}
	cout << cnt;
	return 0;
}










