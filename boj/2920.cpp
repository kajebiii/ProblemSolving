// =====================================================================================
//
//       Filename:  2920.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/19/2016 14:16:40
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
	bool isA, isB; isA = isB = true;
	for(int i=0; i<8; i++)
	{
		int x; cin >> x;
		if(x != (i+1)) isA = false;
		if(x != (8-i)) isB = false;
	}
	if(isA)
		printf("ascending");
	else if(isB)
		printf("descending");
	else
		printf("mixed");
	return 0;
}










