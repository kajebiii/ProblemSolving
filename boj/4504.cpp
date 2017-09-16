// =====================================================================================
//
//       Filename:  4504.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 23:44:43
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
	for(int x; 1;)
	{
		scanf("%d", &x);
		if(x == 0) break;
		if(x % N != 0)
			printf("%d is NOT a multiple of %d.\n", x, N);
		else
			printf("%d is a multiple of %d.\n", x, N);
	}
	return 0;
}










