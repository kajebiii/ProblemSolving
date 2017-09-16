// =====================================================================================
//
//       Filename:  4153.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/03/2016 17:35:53
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
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int main() {
	int A[3];
	while(1)
	{
		for(int i=0; i<3; i++) scanf("%d", &A[i]);
		if(A[0] == 0) break;
		sort(A, A+3);
		if(A[0]*A[0] + A[1]*A[1] == A[2]*A[2])
			puts("right");
		else
			puts("wrong");
	}
	return 0;
}










