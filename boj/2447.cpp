// =====================================================================================
//
//       Filename:  2447.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 13:17:46
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

bool Map[6561][6561];
void fillMap(int a, int b, int k)
{
	if(k == 1)
	{
		Map[a][b] = 1;
		return;
	}
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
		{
			if(i == 1 && j == 1) continue;
			fillMap(a + k/3*i, b + k/3*j, k/3);
		}
}
int main() {
	int N; cin >> N;
	fillMap(0, 0, N);
	for(int i=0; i<N; i++, puts("")) for(int j=0; j<N; j++)
		if(Map[i][j]) printf("*");
		else printf(" ");
	return 0;
}










