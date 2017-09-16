// =====================================================================================
//
//       Filename:  3058.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 12:40:13
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
	int N; cin >> N;
	for(; N--;)
	{
		vector<int> V;
		for(int x, i=0; i<7; i++)
		{
			cin >> x;
			if(x % 2 == 0) V.push_back(x);
		}
		sort(V.begin(), V.end());
		printf("%d %d\n", accumulate(V.begin(), V.end(), 0), V[0]);
	}
	return 0;
}










