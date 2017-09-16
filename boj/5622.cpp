// =====================================================================================
//
//       Filename:  5622.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 21:09:30
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
const int Nr[10] = {-1, -1, 2, 5, 8, 11, 14, 18, 21, 25};
int main() {
	string S; cin >> S;
	int ans = 0;
	for(char x: S)
	{
		for(int i=2; i<=9; i++)
			if(x-'A' > Nr[i-1] && x-'A' <= Nr[i])
				ans += i + 1;
	}
	cout << ans;
	return 0;
}










