// =====================================================================================
//
//       Filename:  1977.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/19/2016 10:01:06
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

#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

int main() {
	int M, N; cin >> M >> N;
	int result = 0, minI = 0x7fffffff;
	for(int i=1; i*i<=N; i++)
		if(i*i >= M)
		{
			result += i*i;
			minI = min(minI, i*i);
		}
	if(minI == 0x7fffffff)
		cout << -1 << endl;
	else
		cout << result << endl << minI;
	return 0;
}










