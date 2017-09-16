// =====================================================================================
//
//       Filename:  5800.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 16:09:46
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

int A[99];
int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++)
	{
		int N; scanf("%d", &N);
		for(int i=0; i<N; i++)
			scanf("%d", &A[i]);
		sort(A, A+N);
		int maxG = 0;
		for(int i=1; i<N; i++)
			maxG = max(maxG, A[i] - A[i-1]);
		printf("Class %d\n", t);
		printf("Max %d, Min %d, Largest gap %d\n", A[N-1], A[0], maxG);
	}
	return 0;
}










