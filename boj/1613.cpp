// =====================================================================================
//
//       Filename:  1613.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/12/2016 17:38:47
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
const int MAX_N = 404;

int N, K;
bool V[MAX_N][MAX_N];
int main() {
	cin >> N >> K;
	while(K--)
	{
		int x, y; scanf("%d%d", &x, &y);
		V[x][y] = true;
	}
	for(int k=1; k<=N; k++) for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		if(V[i][k] == true && V[k][j] == true) V[i][j] = true;

	int Q; cin >> Q;
	while(Q--)
	{
		int x, y; scanf("%d%d", &x, &y);
		if(V[x][y] == true) puts("-1");
		else if(V[y][x] == true) puts("1");
		else puts("0");
	}
	return 0;
}










