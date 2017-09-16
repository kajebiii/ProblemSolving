// =====================================================================================
//
//       Filename:  2852.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/18/2016 16:16:58
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

int Cnt[48*60 + 200][2];
int main() {
	int N; cin >> N;
	for(int i=0; i<N; i++)
	{
		int t, m, s; scanf("%d %02d:%02d", &t, &m, &s); t--;
		Cnt[m*60+s][t]++;
	}

	int S[2] = {0, 0};
	int Ans[2] = {0, 0};
	for(int i=0; i<48*60; i++)
	{
		for(int t=0; t<2; t++) S[t] += Cnt[i][t];
		if(S[0] > S[1]) Ans[0]++;
		else if(S[0] < S[1]) Ans[1]++;
	}
	printf("%02d:%02d\n%02d:%02d\n", Ans[0]/60, Ans[0]%60, Ans[1]/60, Ans[1]%60);
	return 0;
}










