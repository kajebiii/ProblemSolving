// =====================================================================================
//
//       Filename:  10420.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 00:03:15
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

int Day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
	int N; cin >> N;
	int Y = 2014, M = 4, D = 1;
	for(int i=1; i<=N; i++)
	{
		D++;
		if(Y % 4 == 0 && M == 2 && D == 29) continue;
		if(Y % 4 == 0 && M == 2 && D == 30)
		{
			M++;
			D -= 29;
			continue;
		}
		if(D > Day[M])
		{
			D -= Day[M];
			M++; if(M == 13) {Y++; M=1;}
		}
	}
	printf("%d-%02d-%02d\n", Y, M, D);
	return 0;
}










