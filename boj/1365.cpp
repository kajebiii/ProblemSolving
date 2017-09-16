// =====================================================================================
//
//       Filename:  1365.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/10/2016 22:44:02
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
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int A[101101], AN;
int main() {
	int N; cin >> N;
	for(int i=0; i<N; i++)
	{
		int x; scanf("%d", &x);
		int ix = (int)(lower_bound(A, A+AN, x) - A);
		if(ix == AN) AN++;
		A[ix] = x;
	}
	printf("%d\n", N - AN);
	return 0;
}










