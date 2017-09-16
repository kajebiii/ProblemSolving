// =====================================================================================
//
//       Filename:  12760.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 16:33:05
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

int N, M, Nr[111][111], S[111];
int main() {
	cin >> N >> M;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
		scanf("%d", &Nr[i][j]);
	for(int i=1; i<=N; i++) sort(Nr[i]+1, Nr[i]+M+1);
	for(int j=1; j<=M; j++)
	{
		int maxV = -1;
		for(int i=1; i<=N; i++) maxV = max(maxV, Nr[i][j]);
		for(int i=1; i<=N; i++) if(Nr[i][j] == maxV) S[i]++;
	}
	int maxV = -1;
	for(int i=1; i<=N; i++) maxV = max(maxV, S[i]);
	for(int i=1; i<=N; i++) if(S[i] == maxV) printf("%d ", i);
	return 0;
}










