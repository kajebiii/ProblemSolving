// =====================================================================================
//
//       Filename:  12755.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 15:34:48
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
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int main() {
	int N; scanf("%d", &N);
	int l = 1, p = 9, base = 1;
	while(N > l*p)
	{
		N -= l * p;
		base += p;
		l++; p *= 10;
	}
	N--;
	int ans = base + N / l; N %= l; N = l-1 - N;
	for(int i=0; i<N; i++) ans /= 10;
	cout << ans%10;
	return 0;
}










