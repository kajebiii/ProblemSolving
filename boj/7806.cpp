// =====================================================================================
//
//       Filename:  7806.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/24/2016 22:01:47
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
	int N, K;
	while(scanf("%d%d", &N, &K) != EOF)
	{
		int gcd = 1;
		for(int i=2; i*i<=K; i++)
		{
			int cnt = 0;
			while(K % i == 0) cnt++, K /= i;
			int n = N;
			int nCnt = 0;
			while(n) nCnt += n/i, n/=i;

			for(int j=0; j<min(cnt, nCnt); j++)
				gcd *= i;
		}
		if(K != 1 && N >= K) gcd *= K;
		
		printf("%d\n", gcd);
	}
	return 0;
}










