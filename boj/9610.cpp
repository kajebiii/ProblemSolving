// =====================================================================================
//
//       Filename:  9610.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/29/2016 17:37:09
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
	int Q[4] = {0, }, a = 0;
	while(N--)
	{
		int x, y; scanf("%d%d", &x, &y);
		if(x == 0 || y == 0)
		{
			a++;
			continue;
		}
		if(x > 0)
			if(y > 0) Q[0]++;
			else Q[3]++;
		else
			if(y > 0) Q[1]++;
			else Q[2]++;
	}
	for(int i=0; i<4; i++)
		printf("Q%d: %d\n", i+1, Q[i]);
	printf("AXIS: %d\n", a);
	return 0;
}










