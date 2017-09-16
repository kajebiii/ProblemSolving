// =====================================================================================
//
//       Filename:  2571.cpp
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
#include <stack>
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

	for(int j=1; j<=105; j++) for(int i=105; i>=1; i--) if(Map[i][j] != 0) Map[i][j] += Map[i+1][j];

	int result = 0;
	for(int i=1; i<=105; i++)
	{
		stack<int> S;
		int j=1;
		while(j < 106)
		{
			if(S.empty() || Map[i][S.top()] <= Map[i][j])
			{
				S.push(j++);
			}
			else
			{
				int top = S.top(); S.pop();
				int r = j - 1;
				int l = S.empty() ? 1 : S.top() + 1;
				int h = Map[i][top];
				result = max(result, h * (r - l + 1));
			}
		}
	}

	cout << result;

	return 0;
}










