// =====================================================================================
//
//       Filename:  2506.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/16/2016 23:45:09
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
	int N; cin >> N;
	int cnt = 0, sum = 0;
	for(; N--;)
	{
		int x; cin >> x;
		if(x == 1) cnt++;
		if(x == 0) cnt = 0;
		sum += cnt;
	}
	cout << sum;
	return 0;
}










