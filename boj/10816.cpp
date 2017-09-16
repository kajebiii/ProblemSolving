// =====================================================================================
//
//       Filename:  10816.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/29/2016 17:23:13
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
const int MAX_N = 5e5 + 100;

int Nr[MAX_N], N, M;

int main() {
	cin >> N; for(int i=0; i<N; scanf("%d", &Nr[i++]));
	sort(Nr, Nr+N);
	cin >> M;
	while(M--)
	{
		int x; scanf("%d", &x);
		printf("%d ", (int)(upper_bound(Nr, Nr+N, x) - lower_bound(Nr, Nr+N, x)));
	}
	return 0;
}










