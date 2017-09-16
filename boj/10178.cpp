// =====================================================================================
//
//       Filename:  10178.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 18:34:01
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
#include <math.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};

int main() {
	int N; cin >> N;
	while(N--)
	{
		int x, y; scanf("%d%d", &x, &y);
		printf("You get %d piece(s) and your dad gets %d piece(s).\n", x/y, x%y);
	}
	return 0;
}










