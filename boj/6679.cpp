// =====================================================================================
//
//       Filename:  6679.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/07/2016 22:02:49
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

int getNr(int n, int k)
{
	if(n == 0) return 0;
	return getNr(n/k, k) + n%k;
}

int main() {
	for(int i=1000; i<10000; i++)
		if(getNr(i, 10) == getNr(i, 12) && getNr(i, 12) == getNr(i, 16))
			printf("%d\n", i);
	return 0;
}










