// =====================================================================================
//
//       Filename:  2436.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/10/2016 23:54:00
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

int gcd(int a, int b) {return b?gcd(b, a%b):a;}
int main() {
	int A, B; cin >> A >> B; B /= A;
	int last = -1;
	for(int i=1; i*i<=B; i++)
		if(B % i == 0 && gcd(i, B/i) == 1) last = i;
	printf("%d %d\n", A*last, B/last*A);
	return 0;
}










