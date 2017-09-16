// =====================================================================================
//
//       Filename:  9366.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 20:42:43
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
	int N; cin >> N;
	for(int t=1; t<=N; t++)
	{
		int A[3]; for(int i=0; i<3; i++) scanf("%d", &A[i]);
		sort(A, A+3);
		printf("Case #%d: ", t);
		if(A[0] + A[1] <= A[2]) 
		{
			puts("invalid!");
			continue;
		}
		bool a = A[0] == A[1], b = A[1] == A[2];
		if(a && b) puts("equilateral");
		else if(a || b) puts("isosceles");
		else puts("scalene");
	}
	return 0;
}










