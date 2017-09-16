// =====================================================================================
//
//       Filename:  10813.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/29/2016 17:50:15
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

int Nr[111];
int main() {
	int N, M; cin >> N >> M;
	for(int i=1; i<=N; Nr[i] = i, i++);
	while(M--)
	{
		int x, y; scanf("%d%d", &x, &y);
		swap(Nr[x], Nr[y]);
	}
	for(int i=1; i<=N; printf("%d ", Nr[i++]));
	return 0;
}










