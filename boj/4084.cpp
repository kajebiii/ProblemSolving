// =====================================================================================
//
//       Filename:  4084.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 20:39:05
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
	while(1)
	{
		int A[5]; for(int i=0; i<4; i++) cin >> A[i]; A[4] = A[0];
		if(A[0] == 0) break;
		int cnt = 0;
		while(A[0] != A[1] || A[1] != A[2] || A[2] != A[3])
		{
			for(int i=0; i<4; i++) A[i] = abs(A[i+1] - A[i]);
			A[4] = A[0];
			cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}










