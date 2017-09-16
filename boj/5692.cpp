// =====================================================================================
//
//       Filename:  5692.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 02:03:11
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
	int N;
	while(scanf("%d", &N))
	{
		if(N == 0) break;
		int Ans = 0, Fac = 1;
		for(int i=1; N; i++)
		{
			Fac *= i;
			Ans += N%10*Fac;
			N /= 10;
		}
		printf("%d\n", Ans);
	}
	return 0;
}









