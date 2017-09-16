// =====================================================================================
//
//       Filename:  9494.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/27/2016 14:58:28
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
	while(1)
	{
		int N; scanf("%d", &N);
		if(N == 0) break;
		scanf("\n");
		int now = 0;
		for(int i=0; i<N; i++)
		{
			string S; getline(cin, S);
			S = S + ' ';
			for(; now < S.length(); now++)
				if(S[now] == ' ' || S[now] == '\n')
					break;
		}
		printf("%d\n", now+1);
	}
	return 0;
}










