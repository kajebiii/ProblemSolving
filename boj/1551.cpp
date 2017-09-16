// =====================================================================================
//
//       Filename:  1551.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 20:10:56
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

int A[55][55];
int N, K;

int main() {
	cin >> N >> K;
	scanf("%d", &A[0][0]);
	for(int i=1; i<N; i++) scanf(",%d", &A[0][i]);
	for(int k=1; k<=K; k++)
		for(int i=k; i<N; i++)
			A[k][i] = A[k-1][i] - A[k-1][i-1];
	printf("%d", A[K][K]);
	for(int i=K+1; i<N; i++)
		printf(",%d", A[K][i]);
	return 0;
}










