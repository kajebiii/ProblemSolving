// =====================================================================================
//
//       Filename:  11404.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/22/2016 18:07:01
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
const int MAX_N = 111;

int A[MAX_N][MAX_N];

int main() {
	int N, M; cin >> N >> M;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		if(i != j) A[i][j] = INF;
	for(;M--;)
	{
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		A[x][y] = min(A[x][y], c);
	}
	for(int k=1; k<=N; k++) for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		if(A[i][k] != INF && A[k][j] != INF && A[i][j] > A[i][k] + A[k][j])
			A[i][j] = A[i][k] + A[k][j];
	for(int i=1; i<=N; i++, puts("")) for(int j=1; j<=N; printf("%d ", A[i][j]==INF?0:A[i][j]), j++);
	return 0;
}










