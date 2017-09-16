// =====================================================================================
//
//       Filename:  5054.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 00:56:15
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
	int T; cin >> T;
	for(; T--;)
	{
		int N, Nr[99];
		scanf("%d", &N);
		for(int i=0; i<N; i++)
			scanf("%d", &Nr[i]);
		sort(Nr, Nr+N);
		printf("%d\n", 2*(Nr[N-1] - Nr[0]));
	}
	return 0;
}










