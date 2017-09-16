// =====================================================================================
//
//       Filename:  11650.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 01:05:53
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

struct POINT
{
	int x, y;
	const bool operator<(const POINT &o) const
	{
		if(y == o.y) return x < o.x;
		return y < o.y;
	}
}P[111111];
int N;

int main() {
	int N; cin >> N;
	for(int i=0; i<N; i++) scanf("%d%d", &P[i].x, &P[i].y);
	sort(P, P+N);
	for(int i=0; i<N; i++) printf("%d %d\n", P[i].x, P[i].y);
	return 0;
}










