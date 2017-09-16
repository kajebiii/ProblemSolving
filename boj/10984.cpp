// =====================================================================================
//
//       Filename:  10984.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 17:16:27
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
	while(T--)
	{
		int N; scanf("%d", &N);
		double ans = 0;
		int sum = 0;
		for(int i=0; i<N; i++)
		{
			int x; double y;
			scanf("%d%lf", &x, &y);
			ans += 1. * x * y;
			sum += x;
		}
		ans /= 1. * sum;
		printf("%d %.1lf\n", sum, ans);
	}
	return 0;
}










