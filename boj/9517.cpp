// =====================================================================================
//
//       Filename:  9517.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/14/2016 15:42:50
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
	int S; cin >> S; int N; cin >> N; S--;
	int now = 0;
	while(N--)
	{
		int x; char t; scanf("%d %c", &x, &t);
		now += x;
		if(now > 3*60 + 30) {printf("%d\n", S+1); break;}
		if(t == 'T') S = (S+1) % 8;
	}
	return 0;
}










