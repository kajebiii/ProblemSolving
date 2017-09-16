// =====================================================================================
//
//       Filename:  2567.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/19/2016 12:28:30
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

#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

int N, Map[111][111];

int main() {
	cin >> N;
	for(; N--; )
	{
		int x, y; scanf("%d%d", &x, &y);
		for(int i=x; i<x+10; i++) for(int j=y; j<y+10; j++)
			Map[i][j] = 1;
	}

	int result = 0;
	int cx[4] = {-1, 0, 1, 0}, cy[4] = {0, -1, 0, 1};
	for(int i=1; i<=105; i++) for(int j=1; j<=105; j++) if(Map[i][j] == 1) for(int k=0; k<4; k++)
		result += (1 - Map[i + cx[k]][j + cy[k]]);

	cout << result;

	return 0;
}










