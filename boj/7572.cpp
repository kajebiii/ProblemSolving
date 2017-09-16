// =====================================================================================
//
//       Filename:  7572.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 12:51:28
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
	char x = 'F'; int y = 9;
	for(int i=2012; i>=1; i--)
	{
		x--; y--;
		if(x < 'A') x = 'L';
		if(y < 0) y = 9;
	}
	int N; cin >> N;
	for(int i=2; i<=N; i++)
	{
		x++; y++;
		if(x > 'L') x = 'A';
		if(y > 9) y = 0;
	}
	cout << x << y;
	return 0;
}










