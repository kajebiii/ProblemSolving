// =====================================================================================
//
//       Filename:  1233.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/15/2016 17:00:27
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

int Cnt[99];
int main() {
	int A, B, C; cin >> A >> B >> C;
	for(int i=1; i<=A; i++) for(int j=1; j<=B; j++) for(int k=1; k<=C; k++)
		Cnt[i+j+k]++;
	int maxV = -1, maxIx = -1;
	for(int i=0; i<100; i++)
		if(maxV < Cnt[i])
			maxV = Cnt[i], maxIx = i;
	cout << maxIx;
	return 0;
}










