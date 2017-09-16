// =====================================================================================
//
//       Filename:  2493.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/29/2016 17:43:42
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
	stack<pi> S;
	S.push(mp(INF, 0));
	for(int i=1; i<=N; i++)
	{
		int x; scanf("%d", &x);
		while(S.top().first < x) S.pop();
		printf("%d ", S.top().second);
		S.push(mp(x, i));
	}
	return 0;
}










