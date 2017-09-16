// =====================================================================================
//
//       Filename:  2839.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 16:13:22
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
	int ans = INF, N; cin >> N;
	for(int i=N; i>=0; i--)
	{
		if(N - i*5 < 0) continue;
		if((N - i*5) % 3 != 0) continue;
		ans = min(ans, i + (N - i*5) / 3);
	}
	if(ans == INF)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}










