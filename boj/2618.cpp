// =====================================================================================
//
//       Filename:  2618.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/13/2016 12:38:06
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
pi operator -(const pi &x, const pi &y) {return mp(x.fi-y.fi, x.se-y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};
const int MAX_N = 1111, MAX_W = 1111;

int N, W, Dy[MAX_N][MAX_N];
pair<int, pi> P[MAX_N][MAX_N];
pi Ev[MAX_W];
int abs(pi x) {return abs(x.fi) + abs(x.se);}
void printAns(pi k)
{
	if(k.fi == 1 && k.se == 2) return;
	printAns(P[k.fi][k.se].se);
	printf("\n%d", P[k.fi][k.se].fi);
}
int main() {
	cin >> N >> W;
	Ev[1] = mp(1, 1); Ev[2] = mp(N, N); W += 2;
	for(int i=3; i<=W; i++) scanf("%d%d", &Ev[i].fi, &Ev[i].se);
	for(int i=1; i<=W; i++) for(int j=1; j<=W; j++) Dy[i][j] = INF;
	Dy[1][2] = 0;
	for(int k=3; k<=W; k++)
	{
		for(int i=1; i<k; i++)
		{
			if(Dy[i][k-1] != INF && Dy[i][k] > Dy[i][k-1] + abs(Ev[k] - Ev[k-1]))
				Dy[i][k] = Dy[i][k-1] + abs(Ev[k] - Ev[k-1]),
				P[i][k] = mp(2, mp(i, k-1));
			if(Dy[k-1][i] != INF && Dy[k-1][k] > Dy[k-1][i] + abs(Ev[k] - Ev[i]))
				Dy[k-1][k] = Dy[k-1][i] + abs(Ev[k] - Ev[i]),
				P[k-1][k] = mp(2, mp(k-1, i));

			if(Dy[k-1][i] != INF && Dy[k][i] > Dy[k-1][i] + abs(Ev[k] - Ev[k-1]))
				Dy[k][i] = Dy[k-1][i] + abs(Ev[k] - Ev[k-1]),
				P[k][i] = mp(1, mp(k-1, i));
			if(Dy[i][k-1] != INF && Dy[k][k-1] > Dy[i][k-1] + abs(Ev[k] - Ev[i]))
				Dy[k][k-1] = Dy[i][k-1] + abs(Ev[k] - Ev[i]),
				P[k][k-1] = mp(1, mp(i, k-1));
		}
	}
	pi ansIx = mp(-1, -1); int minV = INF;
	for(int i=1; i<=W; i++)
	{
		if(minV > Dy[i][W]) {minV = Dy[i][W]; ansIx = mp(i, W);}
		if(minV > Dy[W][i]) {minV = Dy[W][i]; ansIx = mp(W, i);}
	}
	cout << minV;
	printAns(ansIx);
	return 0;
}










