// =====================================================================================
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 00:58:29
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

int Cnt[2111111], N;
int main() {
	cin >> N;
	for(int x; N--; )
		scanf("%d", &x), Cnt[x+1000000]++;
	for(int i=2000000; i>=0; i--)
		for(int j=0; j<Cnt[i]; j++)
			printf("%d\n", i-1000000);
	return 0;
}










