// =====================================================================================
//
//       Filename:  5724.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/27/2016 15:04:51
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

int Ans[111];
int main() {
	for(int i=1; i<=100; i++)
		Ans[i] = Ans[i-1] + i*i;
	while(1)
	{
		int N; scanf("%d", &N);
		if(N == 0) break;
		printf("%d\n", Ans[N]);
	}
	return 0;
}










