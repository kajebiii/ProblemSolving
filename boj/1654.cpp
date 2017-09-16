// =====================================================================================
//
//       Filename:  1654.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 18:29:26
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
const int MAX_K = 1e4 + 100;

int L[MAX_K];

int main() {
	int K, N; cin >> K >> N;
	for(int i=1; i<=K; i++) scanf("%d", &L[i]);
	
	unsigned int s=0, e=INF, m;
	int ans = 0;
	while(s <= e)
	{
		m = (s+e) / 2;
		int now = 0;
		for(int i=1; i<=K; i++)
			now += L[i] / m;
		if(now >= N)
		{
			ans = m;
			s = m + 1;
		}
		else
			e = m - 1;
	}
	printf("%d", ans);
	return 0;
}










