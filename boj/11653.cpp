// =====================================================================================
//
//       Filename:  11653.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/21/2016 17:18:12
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
	int N; scanf("%d", &N);
	for(int i=2; i*i<=N; i++)
	{
		while(N % i == 0)
		{
			printf("%d\n", i);
			N /= i;
		}
	}
	if(N != 1)
		printf("%d\n", N);
	return 0;
}










