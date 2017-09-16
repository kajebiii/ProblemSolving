// =====================================================================================
//
//       Filename:  9076.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 18:08:58
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
	int T; cin >> T;
	int A[5];
	for(; T--;)
	{
		for(int i=0; i<5; i++) scanf("%d", &A[i]);
		sort(A, A+5);
		if(A[3] - A[1] >= 4)
			puts("KIN");
		else
			cout << accumulate(A+1, A+4, 0) << endl;
	}
	return 0;
}










