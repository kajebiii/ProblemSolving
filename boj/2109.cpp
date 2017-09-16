// =====================================================================================
//
//       Filename:  2019.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/17/2016 15:17:00
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

int N;
vector<int> Ps[11111];
int main() {
	scanf("%d", &N); 
	for(int i=0, p, d; i<N; i++) {scanf("%d%d", &p, &d); Ps[d].pb(p);}
	
	priority_queue<int> Q;
	int ans = 0;
	for(int i=10000; i>=1; i--)
	{
		for(int x : Ps[i]) Q.push(x);
		if(!Q.empty()) {ans += Q.top(); Q.pop();}
	}
	cout << ans;
	return 0;
}










