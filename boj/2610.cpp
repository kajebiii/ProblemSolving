// =====================================================================================
//
//       Filename:  2610.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/13/2016 12:26:57
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

int V[111][111], N, M, Chk[111], MaxV[111];
int main() {
	cin >> N >> M;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) V[i][j] = INF;
	while(M--) {int x, y; scanf("%d%d", &x, &y); V[x][y] = V[y][x] = 1;}
	for(int i=1; i<=N; i++) V[i][i] = 0;
	for(int k=1; k<=N; k++) for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		if(V[i][k] != INF && V[k][j] != INF)
			V[i][j] = min(V[i][j], V[i][k] + V[k][j]);
	for(int i=1; i<=N; i++) MaxV[i] = -1;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) 
		if(V[i][j] != INF) MaxV[i] = max(MaxV[i], V[i][j]);
	vector<int> Ans;
	for(int i=1; i<=N; i++)
	{
		if(Chk[i] == 1) continue;
		int minIx = -1, minV = INF;
		for(int j=1; j<=N; j++) if(V[i][j] != INF) Chk[j] = 1;
		for(int j=1; j<=N; j++)
			if(V[i][j] != INF && minV > MaxV[j])
				minIx = j, minV = MaxV[j];
		Ans.pb(minIx);
	}
	sort(Ans.begin(), Ans.end());
	cout << Ans.size();
	for(int x : Ans) printf("\n%d", x);
	return 0;
}










