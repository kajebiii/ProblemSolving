// =====================================================================================
//
//       Filename:  10419.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 18:36:14
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
	int T; cin >> T;
	while(T--)
	{
		int x; scanf("%d", &x);
		int ans;
		for(ans=0; ans*ans+3*ans+2<=x; ans++);
		printf("%d\n", ans);
	}
	return 0;
}










