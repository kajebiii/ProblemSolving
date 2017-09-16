// =====================================================================================
//
//       Filename:  6591.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 15:16:01
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
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};

ll N, M;
ll C[3001][3001];
int main() {
	C[0][0] = 1;
	for(int i=1; i<=3000; i++)
	{
		C[i][0] = 1;
		for(int j=1; j<=i; j++)
			C[i][j] = C[i-1][j-1] + C[i-1][j];
	}
	while(scanf("%lld%lld", &N, &M))
	{
		if(N == 0) break;
		if(M == 0 || M == N) {printf("1\n"); continue;}
		if(M == 1 || M == N-1) {printf("%lld\n", N); continue;}
		if(M == 2 || M == N-2) {printf("%lld\n", N*(N-1)/2); continue;}
		printf("%lld\n", C[N][M]);
	}
	return 0;
}










