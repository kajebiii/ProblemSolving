// =====================================================================================
//
//       Filename:  1205.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/23/2016 13:58:39
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

int N, S, P, Nr[55];
int main() {
	cin >> N >> S >> P;
	for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	int ans = 0;
	for(int i=0; i<N; i++) if(Nr[i] > S) ans++;
	if(N < P) {printf("%d", ans+1); return 0;}
	else
	{
		if(S <= Nr[N-1]) printf("-1");
		else printf("%d", ans+1);
	}
	return 0;
}










