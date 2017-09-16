// =====================================================================================
//
//       Filename:  10820.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 15:06:26
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
	string S;
	while(getline(cin, S))
	{
		int A[4] = {0, };
		for(char x : S)
		{
			if(x >= 'a' && x <= 'z')
				A[0]++;
			if(x >= 'A' && x <= 'Z')
				A[1]++;
			if(x >= '0' && x <= '9')
				A[2]++;
			if(x == ' ')
				A[3]++;
		}
		for(int i=0; i<4; i++) printf("%d ", A[i]);
		printf("\n");
	}
	return 0;
}










