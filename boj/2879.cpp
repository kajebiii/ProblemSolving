// =====================================================================================
//
//       Filename:  2879.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/19/2016 10:32:47
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

int N, Nr[1111];
int main() {
	cin >> N; for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	for(int i=0, x; i<N; i++) scanf("%d", &x), Nr[i] -= x;
	N++;
	stack<int> S;
	int ans = 0;
	for(int k=0; k<2; k++)
	{
		while(!S.empty()) S.pop();
		for(int i=0; i<N; i++)
		{
			int now = Nr[i];
			if(Nr[i] < 0) now = 0;
			int maxV = now;
			while(!S.empty() && S.top() >= now) {maxV = max(maxV, S.top()); S.pop();}
			ans += maxV - now;
			S.push(now);
		}
		for(int i=0; i<N; i++) Nr[i] *= -1;
	}
	cout << ans;
	return 0;
}










