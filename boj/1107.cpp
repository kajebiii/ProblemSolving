// =====================================================================================
//
//       Filename:  1107.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/10/2016 20:07:01
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
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int N, M, isNot[10];
vector<pi> V;
void findMake(int n, int p)
{
	if(n >= 2000000) return;
	V.pb(mp(n, p));
	if(n == 0) return;
	for(int i=0; i<10; i++)
		if(isNot[i] == 0)
			findMake(n * 10 + i, p+1);
}
int main() {
	cin >> N >> M; for(int x, i=0; i<M; i++) cin >> x, isNot[x] = 1;
	V.pb(mp(100, 0));
	for(int i=0; i<10; i++) if(isNot[i] == 0) findMake(i, 1);
	int Ans = INF;
	for(pi x : V) Ans = min(Ans, abs(N - x.fi) + x.se);
	cout << Ans;
	return 0;
}










