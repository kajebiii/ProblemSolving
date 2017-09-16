// =====================================================================================
//
//       Filename:  9506.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/26/2016 13:24:19
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
	int N;
	while(1)
	{
		scanf("%d", &N);
		if(N == -1) break;
		int sum = 1;
		for(int i=2; i<N; i++)
			if(N % i == 0) sum += i;
		if(sum == N)
		{
			printf("%d = %d", N, 1);
			for(int i=2; i<N; i++)
				if(N % i == 0)
					printf(" + %d", i);
			puts("");
		}
		else printf("%d is NOT perfect.\n", N);
	}
	return 0;
}










