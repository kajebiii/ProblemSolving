// =====================================================================================
//
//       Filename:  1871.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 20:13:57
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

int main() {
	int T; cin >> T;
	while(T--)
	{
		scanf("\n");
		int f = 0;
		for(int i=0; i<3; i++)
		{
			char x; scanf("%c", &x);
			f *= 26;
			f += x - 'A';
		}
		scanf("-");
		int s = 0;
		scanf("%d", &s);
		if(abs(f-s) <= 100) 
			puts("nice");
		else
			puts("not nice");
	}
	return 0;
}










