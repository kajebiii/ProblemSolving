// =====================================================================================
//
//       Filename:  2512.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 14:48:54
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
const int MAX_N = 1e4 + 100;

int N, Nr[MAX_N];

int main() {
	cin >> N; for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	int M; cin >> M;
	int s = 0, e = INF/4, m;
	int ans = -1;
	while(s <= e)
	{
		m = (s + e) / 2;
		int now = 0;
		for(int i=0; i<N; i++)
			now += min(m, Nr[i]);
		if(now <= M)
		{
			s = m + 1;
			ans = m;
		}
		else
			e = m - 1;
	}
	if(ans == INF/4)
		cout << Nr[max_element(Nr, Nr+N) - Nr];
	else
		cout << ans;
	return 0;
}










