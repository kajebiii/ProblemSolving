// =====================================================================================
//
//       Filename:  10995.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 14:50:51
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
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<2*N-1; j++)
			if( (i+j) % 2 == 0)
				printf("*");
			else
				printf(" ");
		if(i%2==1) printf("*");
		puts(" ");
	}
	return 0;
}










