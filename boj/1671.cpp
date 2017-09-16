// =====================================================================================
//
//       Filename:  1671.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/18/2016 15:27:59
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

int N, Nr[1111][3];
int Visit[2222], Match[1111];
vector<int> V[1111*2];

bool findMatch(int v)
{
	if(Visit[v] == 1) return false;
	Visit[v] = 1;
	for(int w : V[v])
		if(Match[w] == -1 || findMatch(Match[w]))
		{
			Match[w] = v;
			return true;
		}
	return false;
}
int main() {
	cin >> N; for(int i=0; i<N; i++) for(int j=0; j<3; j++) scanf("%d", &Nr[i][j]);
	for(int i=0; i<N; i++) for(int j=0; j<N; j++)
	{
		bool isBig = true;
		for(int k=0; k<3; k++) if(Nr[i][k] < Nr[j][k]) isBig = false;
		if(isBig)
		{
			if(accumulate(Nr[i], Nr[i]+3, 0) == accumulate(Nr[j], Nr[j]+3, 0) && i <= j) continue;
			V[i*2+0].pb(j); V[i*2+1].pb(j);
		}
	}
	int ans = 0;
	for(int i=0; i<N; i++) Match[i] = -1;
	for(int i=0; i<2*N; i++)
	{
		for(int j=0; j<2*N; j++) Visit[j] = 0;
		if(findMatch(i)) ans++;
	}
	cout << N - ans;
	return 0;
}










