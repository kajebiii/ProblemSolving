// =====================================================================================
//
//       Filename:  10219.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/24/2016 00:19:36
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
	for(; T--;)
	{
		int H, W; scanf("%d%d", &H, &W);
		for(int i=0; i<H; i++)
		{
			string S; cin >> S;
			reverse(S.begin(), S.end());
			cout << S << endl;
		}
	}
	return 0;
}










