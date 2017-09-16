// =====================================================================================
//
//       Filename:  2942.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 00:32:19
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

int gcd(int a, int b) {return a?gcd(b%a, a):b;}

int main() {
	int R, G; cin >> R >> G;
	int C = gcd(R, G);
	for(int i=1; i*i<=C; i++)
	{
		if(C%i) continue;
		printf("%d %d %d\n", i, R/i, G/i);
		if(i*i != C)
			printf("%d %d %d\n", C/i, R/(C/i), G/(C/i));
	}
	return 0;
}










