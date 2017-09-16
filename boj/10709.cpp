// =====================================================================================
//
//       Filename:  10709.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/18/2016 16:12:26
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

char A[111];
int main() {
	int H, W;
	cin >> H >> W;
	for(int i=0; i<H; i++)
	{
		scanf("%s", A);
		bool first = false; int cnt = 0;
		for(int j=0; j<W; j++)
		{
			if(A[j] == 'c') first = true, cnt = 0;
			else cnt++;
			if(first == false) printf("-1 ");
			else printf("%d ", cnt);
		}
		puts("");
	}
	return 0;
}










