// =====================================================================================
//
//       Filename:  5355.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 16:42:26
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
	int T; cin >> T;
	while(T--)
	{
		double x; cin >> x;
		string S; getline(cin, S);
		for(char k : S)
			if(k == '@')
				x *= 3;
			else if(k == '%')
				x += 5;
			else if(k == '#')
				x -= 7;
		printf("%.02lf\n", x);
	}
	return 0;
}










