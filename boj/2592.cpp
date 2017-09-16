// =====================================================================================
//
//       Filename:  2592.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 16:48:53
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

int Cnt[1111];

int main() {
	int sum = 0;
	int maxN, maxC = -1;
	for(int i=0; i<10; i++)
	{
		int x; cin >> x;
		sum += x;
		Cnt[x]++;
		if(maxC < Cnt[x])
		{
			maxN = x;
			maxC = Cnt[x];
		}
	}
	cout << sum / 10 << endl << maxN << endl;
	return 0;
}










