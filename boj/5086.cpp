// =====================================================================================
//
//       Filename:  5086.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/21/2016 17:33:34
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
	int x, y;
	while(1)
	{
		scanf("%d%d", &x, &y);
		if(x == 0) break;
		if(y % x == 0)
			puts("factor");
		else if(x % y == 0)
			puts("multiple");
		else
			puts("neither");
	}
	return 0;
}










