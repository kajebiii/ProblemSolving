// =====================================================================================
//
//       Filename:  6988.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 13:20:19
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

ll N, Nr[3333], Dy[3333][3333], Idx[1001001];
int main() {
	cin >> N; for(int i=1; i<=N; i++) scanf("%lld", &Nr[i]), Idx[Nr[i]] = i;
	for(int i=1; i<=N; i++) for(int j=i+1; j<=N; j++)
		Dy[i][j] = Nr[i] + Nr[j];

	ll ans = 0;
	for(int i=1; i<=N; i++) for(int j=i+1; j<=N; j++)
	{
		int past = Nr[i] * 2 - Nr[j];
		if(past < 0) continue;
		if(Idx[past] == 0) continue;
		Dy[i][j] = max(Dy[i][j], Dy[Idx[past]][i] + Nr[j]);
		ans = max(ans, Dy[i][j]);
	}
	cout << ans;
	return 0;
}










