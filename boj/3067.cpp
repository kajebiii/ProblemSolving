// =====================================================================================
//
//       Filename:  3067.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/17/2016 14:56:57
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

int N, Nr[22], Dy[11111], M;
int main() {
	int TC; cin >> TC;
	while(TC--)
	{
		scanf("%d", &N); for(int i=0; i<N; i++) scanf("%d", &Nr[i]); scanf("%d", &M);
		for(int i=0; i<=M; i++) Dy[i] = 0; Dy[0] = 1;
		for(int i=0; i<N; i++)
			for(int j=Nr[i]; j<=M; j++)
				Dy[j] += Dy[j-Nr[i]];
		printf("%d\n", Dy[M]);
	}
	return 0;
}










