// =====================================================================================
//
//       Filename:  2799.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/14/2016 17:35:22
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

char Map[555][555]; int Cnt[5];
int main() {
	int N, M; cin >> N >> M;
	for(int i=0; i<5*N+1; i++) scanf("%s", Map[i]);
	for(int i=0; i<N; i++) for(int j=0; j<M; j++)
	{
		int cnt = 0;
		for(int k=0; k<4; k++)
			if(Map[i*5+1+k][j*5+1] == '*') cnt++;
		Cnt[cnt]++;
	}
	for(int i=0; i<5; i++) printf("%d ", Cnt[i]);
	return 0;
}










