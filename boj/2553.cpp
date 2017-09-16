// ====================================================================================
//
//       Filename:  2553.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/13/2016 02:34:12
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
	int Other = 1, Two = 1; // 2 4 8 6
	int N; cin >> N;
	for(int i=1; i<=N; i++)
	{
		int now = i;
		while(now % 2 == 0) {Two *= 2, Two %= 10, now /= 2;}
		while(now % 5 == 0) 
		{
			Two /= 2;
			if(Two % 2) Two += 5;
			now /= 5;
		}
		Other *= now;
		Other %= 10;
	}
	printf("%d", Other*Two%10);
	return 0;
}










