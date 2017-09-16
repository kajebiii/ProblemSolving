// =====================================================================================
//
//       Filename:  2774.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 19:07:33
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

int C[10];
int beauty(int x)
{
	for(int i=0; i<10; i++) C[i] = 0;
	for(; x; x/=10) C[x%10]=1;
	return accumulate(C, C+10, 0);
}

int main() {
	int T; cin >> T;
	for(; T--;)
	{
		int x; scanf("%d", &x);
		printf("%d\n", beauty(x));
	}
	return 0;
}










