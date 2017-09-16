// =====================================================================================
//
//       Filename:  1268.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/21/2016 23:10:42
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
#include <assert.h>

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

int Nr[1111][5], N;
int main() {
	scanf("%d", &N);
	for(int i=1; i<=N; i++) for(int j=0; j<5; j++) scanf("%d", &Nr[i][j]);
	int maxV = -1, maxIx = -1;
	for(int i=1; i<=N; i++)
	{
		int cnt = 0;
		for(int j=1; j<=N; j++)
		{
			bool same = false;
			for(int k=0; k<5; k++) if(Nr[i][k] == Nr[j][k]) same = true;
			if(same) cnt += 1;
		}
		if(maxV < cnt) {maxV = cnt, maxIx = i;}
	}
	cout << maxIx;
	return 0;
}










