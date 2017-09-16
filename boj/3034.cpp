// =====================================================================================
//
//       Filename:  3034.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 17:24:47
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
	int N, W, H; cin >> N >> W >> H;
	int a = W*W + H*H;
	for(int i=0; i<N; i++)
	{
		int x; scanf("%d", &x);
		x = x * x;
		if(x <= a)
			puts("DA");
		else
			puts("NE");
	}
	return 0;
}










