// =====================================================================================
//
//       Filename:  1357.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/22/2016 00:53:10
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

int re(int x)
{
	int r = 0;
	while(x)
	{
		r *= 10;
		r += x%10;
		x/=10;
	}
	return r;
}

int main() {
	int x, y; cin >> x >> y;
	cout << re(re(x)+re(y));
	return 0;
}










