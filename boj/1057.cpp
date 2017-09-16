// =====================================================================================
//
//       Filename:  1057.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/21/2016 23:46:25
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

int main() {
	int N, X, Y; cin >> N >> X >> Y;
	if(X > Y) swap(X, Y);
	int cnt = 0;
	while(N != 1)
	{
		cnt++;
		X = (X+1)/2;
		Y = (Y+1)/2;
		if(X == Y)
		{
			cout << cnt;
			return 0;
		}
		N = (N+1)/2;
	}
	return 0;
}










