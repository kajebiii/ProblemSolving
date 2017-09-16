// =====================================================================================
//
//       Filename:  5575.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 20:47:13
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
	for(int k=0; k<3; k++)
	{
		int A[3]; for(int i=0; i<3; i++) scanf("%d", &A[i]), A[i] *= -1;
		for(int i=0, x; i<3; i++) scanf("%d", &x), A[i] += x;
		for(int i=2; i>=1; i--)
			if(A[i] < 0) A[i-1] -= 1, A[i] += 60;
		for(int i=0; i<3; i++) printf("%d ", A[i]);
		puts("");
	}
	return 0;
}










