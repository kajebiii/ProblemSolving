// =====================================================================================
//
//       Filename:  9251.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 15:08:17
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

int Dy[1111][1111];
int main() {
	string A, B; cin >> A >> B;

	int ans = 0;
	for(int i=0; i<A.length(); i++) for(int j=0; j<B.length(); j++)
	{
		if(i != 0) Dy[i][j] = max(Dy[i][j], Dy[i-1][j]);
		if(j != 0) Dy[i][j] = max(Dy[i][j], Dy[i][j-1]);
		if(A[i] == B[j])
		{
			if(i == 0 || j == 0)
				Dy[i][j] = max(Dy[i][j], 1);
			else
				Dy[i][j] = max(Dy[i][j], Dy[i-1][j-1] + 1);
		}
		ans = max(ans, Dy[i][j]);
	}
	cout << ans;
	return 0;
}










