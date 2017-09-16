// =====================================================================================
//
//       Filename:  5623.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/18/2016 13:38:58
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

int N, Nr[1111][1111];
int main() {
	cin >> N; for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) scanf("%d", &Nr[i][j]);
	if(N == 2) {printf("1 %d\n", Nr[1][2]-1); return 0;}
	printf("%d %d", (Nr[1][2]+Nr[1][3]-Nr[2][3])/2, (Nr[1][2]+Nr[2][3]-Nr[1][3])/2);
	for(int i=3; i<=N; i++)
		printf(" %d", (Nr[i-2][i]+Nr[i-1][i]-Nr[i-2][i-1])/2);
	return 0;
}










