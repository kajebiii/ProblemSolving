// =====================================================================================
//
//       Filename:  2959.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 16:13:21
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
	int A[4]; for(int i=0; i<4; i++) cin >> A[i];
	int ans = 0;
	for(int i=0; i<4; i++) for(int j=i+1; j<4; j++)
	{
		int h = INF;
		for(int k=0; k<4; k++)
			if(k!=i && k!=j) h = min(h, A[k]);
		ans = max(ans, min(A[i], A[j]) * h);
	}
	cout << ans;
	return 0;
}










