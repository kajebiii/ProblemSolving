// =====================================================================================
//
//       Filename:  8320.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/28/2016 19:02:06
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

int main() {
	int N; cin >> N;
	int ans = 0;
	for(int i=1; i<=N; i++)
		for(int j=i; j<=N; j++)
		{
			if(i*j > N) break;
			ans++;
		}
	cout << ans;
	return 0;
}










