// =====================================================================================
//
//       Filename:  5176.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 00:26:57
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
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

bool Chk[555];

int main() {
	int T; cin >> T;
	while(T--)
	{
		int P, M; scanf("%d%d", &P, &M);
		for(int i=0, x; i<P; i++) scanf("%d", &x), Chk[x] = true;
		int cnt = 0;
		for(int i=1; i<=M; i++) cnt += Chk[i];
		cout << P - cnt << endl;
		for(int i=1; i<=M; i++) Chk[i] = false;
	}
	return 0;
}










