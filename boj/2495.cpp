// =====================================================================================
//
//       Filename:  2495.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/29/2016 17:34:55
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
	int N;
	while(scanf("%d", &N) != EOF)
	{
		int ans = -1, cnt = 0, last = -1;
		while(N)
		{
			int now = N % 10;
			if(last != now)
				cnt = 1;
			else
				cnt = cnt + 1;
			ans = max(ans, cnt);
			last = now;
			N /= 10;
		}
		printf("%d\n", ans);
	}
	return 0;
}










