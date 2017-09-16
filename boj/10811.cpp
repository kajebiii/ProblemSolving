// =====================================================================================
//
//       Filename:  10811.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 23:06:03
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
#include <math.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};
const int MAX_N = 111;

int N, M;
int Nr[MAX_N];

int main() {
	cin >> N >> M;
	for(int i=1; i<=N; i++) Nr[i] = i;
	while(M--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		reverse(Nr + x, Nr + y + 1);
	}
	for(int i=1; i<=N; i++) printf("%d ", Nr[i]);
	return 0;
}










