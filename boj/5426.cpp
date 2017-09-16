// =====================================================================================
//
//       Filename:  5426.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 22:20:16
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
	int TC; cin >> TC;
	while(TC--)
	{
		string S; cin >> S; int N = S.length();
		int sqrtN = 0;
		for(; (sqrtN+1)*(sqrtN+1) <= N; sqrtN++);
		for(int i=0; i<sqrtN; i++) for(int j=0; j<sqrtN; j++)
			printf("%c", S[j*sqrtN + (sqrtN-1-i)]);
		puts("");
	}
	return 0;
}










