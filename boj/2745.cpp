// =====================================================================================
//
//       Filename:  2745.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 14:23:23
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
	string S; cin >> S; int K; cin >> K;

	int ans = 0;
	int power = 1;
	for(int i=S.length()-1; i>=0; i--)
	{
		int x = S[i] - '0';
		if(S[i] >= 'A') x = S[i] - 'A' + 10;
		ans += x * power;
		power *= K;
	}
	cout << ans;
	return 0;
}










