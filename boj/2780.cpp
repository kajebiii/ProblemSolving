// =====================================================================================
//
//       Filename:  2780.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 17:27:23
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
const int MAX_N = 1111;
const int MOD = 1234567;

vector<int> V[11];
int Dy[1111][11];
int main() {
	V[0].pb(7); V[7].pb(0);
	for(int i=2; i<=8; i+=3) V[i].pb(i-1), V[i-1].pb(i), V[i].pb(i+1), V[i+1].pb(i);
	for(int i=4; i<=6; i++)  V[i].pb(i-3), V[i-3].pb(i), V[i].pb(i+3), V[i+3].pb(i);
	for(int i=0; i<=9; i++)  V[i].pb(10);
	Dy[0][10] = 1;
	for(int i=1; i<=1000; i++) for(int j=0; j<10; j++)
		for(int x : V[j]) Dy[i][j] = (Dy[i][j] + Dy[i-1][x]) % MOD;

	int T; cin >> T;
	while(T--)
	{
		int N; scanf("%d", &N);
		printf("%d\n", accumulate(Dy[N], Dy[N]+10, 0) % MOD);
	}
	return 0;
}










