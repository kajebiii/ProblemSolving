// =====================================================================================
//
//       Filename:  10992.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 14:30:25
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
	for(int i=0; i<N-1; i++, puts(""))
		for(int j=0; j<N+i; j++)
			if(abs(N-1-j) == i)
				printf("*");
			else
				printf(" ");
	for(int i=0; i<2*N-1; i++)
		printf("*");
	return 0;
}










