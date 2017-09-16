// =====================================================================================
//
//       Filename:  2997.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/09/2016 10:21:39
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
	int A[3]; for(int i=0; i<3; i++) scanf("%d", &A[i]);
	sort(A, A+3);
	if(A[1] - A[0] == A[2] - A[1]) printf("%d", A[2] + A[1] - A[0]);
	else
	{
		if(A[1] - A[0] < A[2] - A[1]) printf("%d", (A[2] + A[1]) / 2);
		else printf("%d", (A[1] + A[0]) / 2);
	}
	return 0;
}










