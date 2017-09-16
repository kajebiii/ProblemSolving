// =====================================================================================
//
//       Filename:  9468.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/18/2016 15:19:39
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

int Nr[15];
int main() {
	int TC; cin >> TC;
	while(TC--)
	{
		int t; scanf("%d", &t); int N = 15;
		for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
		stack<int> S;
		int ans = 0;
		for(int i=0; i<N; i++)
		{
			while(!S.empty() && S.top() > Nr[i]) S.pop();
			if(Nr[i] == 0) continue;
			if(S.empty() || S.top() < Nr[i])
			{
				ans++;
				S.push(Nr[i]);
			}
		}
		printf("%d %d\n", t, ans);
	}
	return 0;
}










