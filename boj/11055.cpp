// =====================================================================================
//
//       Filename:  11055.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/24/2016 00:26:13
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
const int MAX_N = 1e3 + 10;

int N, Nr[MAX_N], Dy[MAX_N];

int main() {
	cin >> N;
	for(int i=1; i<=N; i++)
		scanf("%d", &Nr[i]);

	int ans = 0;
	for(int i=1; i<=N; i++)
	{
		for(int j=0; j<i; j++)
			if(Nr[j] < Nr[i])
				Dy[i] = max(Dy[i], Dy[j] + Nr[i]);
		ans = max(ans, Dy[i]);
	}
	cout << ans;
	return 0;
}










