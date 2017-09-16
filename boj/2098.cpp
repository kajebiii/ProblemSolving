// =====================================================================================
//
//       Filename:  2098.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/03/2016 01:34:31
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

const int INF = 1000000000;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};
const int MAX_N = 16;

int N, W[MAX_N][MAX_N], Dy[1<<MAX_N][MAX_N];

int getAns(int state, int v)
{
	if(Dy[state][v]) return Dy[state][v] - 1;
	int result = INF;
	for(int i=0; i<N; i++)
	{
		if( (state & 1<<i) == 0) continue;
		if(W[i][v] == 0) continue;
		result = min(result, getAns(state - (1<<v), i) + W[i][v]);
	}
	Dy[state][v] = result + 1;
	return result;
}
int main() {
	cin >> N; for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf("%d", &W[i][j]);
	int ans = INF;
	for(int i=0; i<N; i++)
	{
		if(W[0][i]) 
		{
			for(int k=0; k<(1<<N); k++) for(int j=0; j<N; j++) Dy[k][j] = 0;
			for(int j=0; j<N; j++) Dy[1<<j][j] = 1000000000;
			Dy[1<<i][i] = 1;
			ans = min(ans, getAns((1<<N)-1, 0) + W[0][i]);
		}
	}
	cout << ans;
	return 0;
}










