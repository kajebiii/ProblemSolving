// =====================================================================================
//
//       Filename:  11286.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/24/2016 03:25:22
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
#include <assert.h>

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
	int N; cin >> N;
	priority_queue<pi, vector<pi>, greater<pi> > Q;
	for(int i=0; i<N; i++)
	{
		int x; scanf("%d", &x);
		if(x == 0)
		{
			if(Q.empty()) {puts("0"); continue;}
			int y, t; tie(y, t) = Q.top(); Q.pop();
			printf("%d\n", y * t);
		}
		else
		{
			int y = abs(x), t = x / y;
			Q.push(mp(y, t));
		}
	}
	return 0;
}










