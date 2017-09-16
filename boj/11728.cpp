// =====================================================================================
//
//       Filename:  11728.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/27/2016 14:47:39
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

using namespace std;

typedef pair<int, int> pi;
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};
const int MAX_N = 1e6 + 100;

int A[MAX_N], B[MAX_N];
int main() {
	int N, M; cin >> N >> M;
	for(int i=0; i<N; i++) scanf("%d", &A[i]);
	for(int i=0; i<M; i++) scanf("%d", &B[i]);
	int a = 0, b = 0;
	while(a < N || b < M)
	{
		if(b == M || (a < N && A[a] <= B[b]) )
			printf("%d ", A[a++]);
		else
			printf("%d ", B[b++]);
	}
	return 0;
}










