// =====================================================================================
//
//       Filename:  10974.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 12:55:01
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

int main() {
	int N; cin >> N;
	int A[9];
	for(int i=0; i<N; i++) A[i] = i+1;
	do
	{
		for(int i=0; i<N; i++) printf("%d ", A[i]); printf("\n");
	}while(next_permutation(A, A+N));
	return 0;
}










