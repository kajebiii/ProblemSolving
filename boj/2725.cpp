// =====================================================================================
//
//       Filename:  2725.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/23/2016 09:44:41
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
#include <assert.h>

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

int gcd(int a, int b) {return b?gcd(b, a%b):a;}
int Ans[1111][1111];
int main() {
	for(int i=0; i<=1000; i++) for(int j=0; j<=1000; j++)
	{
		int now = (gcd(i, j) == 1 ? 1 : 0);
		int d = (i==0 ? 0 : Ans[i-1][j]);
		int l = (j==0 ? 0 : Ans[i][j-1]);
		int dl = (i>0 && j>0 ? Ans[i-1][j-1] : 0);
		Ans[i][j] = d + l - dl + now;
	}
	int TC; cin >> TC;
	while(TC--)
	{
		int N; scanf("%d", &N);
		printf("%d\n", Ans[N][N]);
	}
	return 0;
}










