// =====================================================================================
//
//       Filename:  4388.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 16:10:22
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
	ll A, B;
	while(scanf("%lld%lld", &A, &B))
	{
		if(A == 0 && B == 0) break;

		int C = 0, Ans =0;
		while(A != 0 || B != 0)
		{
			int now = A%10 + B%10 + C;
			C = now/10; Ans += C;
			A/=10; B/=10;
		}
		printf("%d\n", Ans);
	}
	return 0;
}










