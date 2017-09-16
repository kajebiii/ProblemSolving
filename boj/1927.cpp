// =====================================================================================
//
//       Filename:  1927.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 14:38:13
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

priority_queue<int, vector<int>, greater<int> > Q;

int main() {
	int N; cin >> N;
	for(; N--;)
	{
		int x; scanf("%d", &x);
		if(x == 0)
		{
			if(Q.empty())
				printf("0\n");
			else
			{
				printf("%d\n", Q.top());
				Q.pop();
			}
		}
		else
			Q.push(x);
	}
	return 0;
}










