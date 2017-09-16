// =====================================================================================
//
//       Filename:  2960.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 23:08:27
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
const int MAX_N = 1111;

bool notP[MAX_N];

int main() {
	notP[1] = true;
	int N, K; cin >> N >> K;
	int cnt = 0;
	for(int i=2; i<=N; i++)
	{
		if(notP[i] == true) continue;
		for(int j=i; j<=N; j+=i)
		{
			if(notP[j] == true) continue;
			cnt++;
			notP[j] = true;
			if(cnt == K)
			{
				printf("%d\n", j);
				return 0;
			}
		}
	}
	return 0;
}










