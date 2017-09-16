// =====================================================================================
//
//       Filename:  2581.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/24/2016 00:28:31
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

const int MAX_N = 10000;

bool notP[11111];

int main() {
	notP[1] = true;
	for(int i=2; i<=MAX_N; i++)
	{
		if(notP[i] == true) continue;
		for(int j=i*2; j<=MAX_N; j+=i)
			notP[j] = true;
	}
	int M, N; cin >> M >> N;
	int ans = 0, ansMin = -1;
	for(int i=N; i>=M; i--)
		if(notP[i] == false)
			ans += i, ansMin = i;
	if(ans == 0)
		cout << -1;
	else
		cout << ans << endl << ansMin;
	return 0;
}










