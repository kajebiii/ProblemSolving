// =====================================================================================
//
//       Filename:  3029.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 20:25:45
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
	int A[3], B[3];
	scanf("%2d:%2d:%2d\n%2d:%2d:%2d", &A[0], &A[1], &A[2], &B[0], &B[1], &B[2]);
	for(int i=1; i<=24*60*60; i++)
	{
		A[2]++;
		A[1] += A[2] / 60; A[2] %= 60;
		A[0] += A[1] / 60; A[1] %= 60;
		A[0] %= 24;

		if(A[0] == B[0] && A[1] == B[1] && A[2] == B[2])
			printf("%02d:%02d:%02d\n", i/3600, (i/60)%60, i%60);
	}
	return 0;
}










