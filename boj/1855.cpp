// =====================================================================================
//
//       Filename:  1855.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 21:09:29
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

char A[222][222];
int main() {
	int N; cin >> N; string S; cin >> S;
	for(int i=0; i<S.length()/N; i++)
	{
		if(i%2 == 0) for(int j=0; j<N; j++)
			A[i][j] = S[i*N + j];
		if(i%2 == 1) for(int j=0; j<N; j++)
			A[i][N-1-j] = S[i*N + j];
	}
	for(int j=0; j<N; j++) for(int i=0; i<S.length()/N; i++)
		printf("%c", A[i][j]);
	return 0;
}










