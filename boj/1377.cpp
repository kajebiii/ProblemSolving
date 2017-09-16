// =====================================================================================
//
//       Filename:  1377.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/22/2016 00:10:02
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
const int MAX_N = 5e5 + 500;

int N, Nr[MAX_N], Sx[MAX_N];
map<int, int> M;
int main() {
	cin >> N; for(int i=0; i<N; i++) scanf("%d", &Nr[i]), Sx[i] = Nr[i], M[Nr[i]] = 0;
	sort(Sx, Sx+N);
	int ans = 0;
	for(int i=0; i<N; i++)
	{
		int ix = (int)(lower_bound(Sx, Sx+N, Nr[i]) - Sx) + M[Nr[i]]++;
		if(ix < i) ans = max(i - ix, ans);
	}
	cout << ans + 1;
	return 0;
}










