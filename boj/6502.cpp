// =====================================================================================
//
//       Filename:  6502.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 20:31:00
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
	int T = 0;
	while(1)
	{
		int A[3]; 
		scanf("%d", &A[0]);
		if(A[0] == 0) break;
		for(int i=1; i<3; i++) scanf("%d", &A[i]);
		printf("Pizza %d ", ++T);
		if(4*A[0]*A[0] >= A[1]*A[1]+A[2]*A[2])
			puts("fits on the table.");
		else
			puts("does not fit on the table.");
	}
	return 0;
}










