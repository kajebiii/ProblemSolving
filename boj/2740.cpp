// =====================================================================================
//
//       Filename:  2740.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 00:49:29
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

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int A[111][111], B[111][111];
int main() {
	int N, M; cin >> N >> M;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) scanf("%d", &A[i][j]);
	int K; cin >> M >> K;
	for(int i=1; i<=M; i++) for(int j=1; j<=K; j++) scanf("%d", &B[i][j]);
	for(int i=1; i<=N; i++) for(int j=1; j<=K; j++)
	{
		int now = 0;
		for(int k=1; k<=M; k++)
			now += A[i][k] * B[k][j];
		printf("%d ", now);
		if(j == K) printf("\n");
	}
	return 0;
}










