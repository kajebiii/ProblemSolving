// =====================================================================================
//
//       Filename:  3062.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 16:08:00
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

int re(int x)
{
	int r = 0;
	while(x)
		r *= 10, r += x % 10, x /= 10;
	return r;
}
int pa(int x)
{
	if(re(x) == x) return 1;
	return 0;
}

int main() {
	int T; cin >> T;
	while(T--)
	{
		int x; scanf("%d", &x);
		x = x + re(x);
		if(pa(x)) puts("YES");
		else puts("NO");
	}
	return 0;
}










