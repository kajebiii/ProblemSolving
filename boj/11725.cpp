// =====================================================================================
//
//       Filename:  11725.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/03/2016 02:15:23
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
const int MAX_N = 1e5 + 100;

int N, P[MAX_N];
vector<int> V[MAX_N];

void findP(int v, int p)
{
	P[v] = p;
	for(int x : V[v])
	{
		if(x == p) continue;
		findP(x, v);
	}
}
int main() {
	scanf("%d", &N);
	for(int i=1; i<N; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		V[x].pb(y); V[y].pb(x);
	}
	findP(1, -1);
	for(int i=2; i<=N; i++)
		printf("%d\n", P[i]);
	return 0;
}










