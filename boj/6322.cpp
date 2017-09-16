// =====================================================================================
//
//       Filename:  6322.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 18:49:25
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
	int A[3], t = 0;
	while(++t)
	{
		for(int i=0; i<3; i++) scanf("%d", &A[i]);
		if(A[0] == 0 && A[1] == 0 && A[2] == 0) break;
		if(t != 1) puts("");
		printf("Triangle #%d\n", t);
		if(A[2] == -1)
		{
			printf("c = %.3lf\n", sqrt(A[0]*A[0] + A[1]*A[1]));
			continue;
		}
		int val = A[2]*A[2] - A[1]*A[1] - A[0]*A[0] + 1;
		if(val <= 0) {puts("Impossible."); continue;}
		if(A[1] == -1) printf("b = ");
		else printf("a = ");
		printf("%.3lf\n", sqrt(val));
	}
	return 0;
}










