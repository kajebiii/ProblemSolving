// =====================================================================================
//
//       Filename:  4811.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/07/2016 09:40:58
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

ll Dy[33];
int main() {
	Dy[0] = Dy[1] = 1;
	for(int i=2; i<=30; i++)
		for(int j=0; j<i; j++)
			Dy[i] += Dy[j] * Dy[i-1-j];
	int N;
	while(scanf("%d", &N))
	{
		if(N == 0) break;
		printf("%lld\n", Dy[N]);
	}
	return 0;
}










