// =====================================================================================
//
//       Filename:  11170.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/13/2016 12:22:54
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

int Sum[1001001];
int cntZ(int v)
{
	int cnt = 0;
	do{if(v%10==0) cnt++;}while(v/=10);
	return cnt;
}
int main() {
	int T; cin >> T;
	Sum[0] = 1;
	for(int i=1; i<=1000000; i++)
		Sum[i] = Sum[i-1] + cntZ(i);
	while(T--)
	{
		int x, y; scanf("%d%d", &x, &y);
		printf("%d\n", Sum[y] - (x==0?0:Sum[x-1]));
	}
	return 0;
}










