// =====================================================================================
//
//       Filename:  2161.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/24/2016 00:16:34
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
	deque<int> Q;
	for(int i=1; i<=N; i++) Q.push_back(i);
	while(!Q.empty())
	{
		int now = Q.front(); Q.pop_front();
		printf("%d ", now);
		now = Q.front(); Q.pop_front(); Q.push_back(now);
	}
	return 0;
}










