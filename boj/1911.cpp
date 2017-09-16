// =====================================================================================
//
//       Filename:  1911.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  10/04/2016 14:54:56
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

int N, L;
pi Nr[11111];
int main() {
	cin >> N >> L;
	for(int i=0; i<N; i++) scanf("%d%d", &Nr[i].fi, &Nr[i].se), Nr[i].se--;
	sort(Nr, Nr+N);
	
	int r = -INF, cnt = 0;
	for(int i=0; i<N; i++)
	{
		if(r-1 >= Nr[i].se) continue;
		Nr[i].fi = max(Nr[i].fi, r);
		int plus = (Nr[i].se - Nr[i].fi + 1 + (L-1)) / L; 
		cnt += plus;
		r = Nr[i].fi + plus * L;
		if(debug) printf("plus %d / cnt %d / r %d\n", plus, cnt, r);
	}
	cout << cnt;
	return 0;
}










