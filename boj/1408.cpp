// =====================================================================================
//
//       Filename:  1408.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 15:29:31
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
	int A[2][3];
	for(int i=0; i<2; i++)
		scanf("%02d:%02d:%02d", &A[i][0], &A[i][1], &A[i][2]);
	for(int i=0; i<3; i++)
		A[1][i] -= A[0][i];
	if(A[1][2] < 0) A[1][2] += 60, A[1][1] -= 1;
	if(A[1][1] < 0) A[1][1] += 60, A[1][0] -= 1;
	if(A[1][0] < 0) A[1][0] += 24;
	printf("%02d:%02d:%02d\n", A[1][0], A[1][1], A[1][2]);
	return 0;
}










