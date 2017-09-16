// =====================================================================================
//
//       Filename:  2790.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/22/2016 16:56:56
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
const int MAX_N = 3e5 + 100;

int N, Nr[MAX_N], MaxV[MAX_N];
int main() {
	cin >> N; for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	sort(Nr, Nr+N);
	MaxV[N] = -INF; for(int i=N-1; i>=0; i--) MaxV[i] = max(MaxV[i+1], Nr[i] + N-i);

	int ans = 0, nowV = -INF;
	for(int i=0; i<N; i++)
	{
		int you = Nr[i] + N;
		if(you >= nowV && you >= MaxV[i+1]) ans++;
		nowV = max(nowV, Nr[i] + N-i-1);
	}
	cout << ans;
	return 0;
}










