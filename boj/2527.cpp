// =====================================================================================
//
//       Filename:  2527.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 18:55:21
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

int get(int a0, int a1, int b0, int b1)
{
	if(a1 == b0 || a0 == b1) return 1;
	if(a1 < b0 || b1 < a0) return 0;
	return 2;
}
map<int, char> M;
int main() {
	M[0] = 'd'; M[1] = 'c'; M[2] = 'b'; M[4] = 'a';
	for(int k=0; k<4; k++)
	{
		int A[8]; for(int i=0; i<8; i++) scanf("%d", &A[i]);
		printf("%c\n", M[get(A[0], A[2], A[4], A[6])*get(A[1], A[3], A[5], A[7])]);
	}
	return 0;
}










