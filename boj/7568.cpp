// =====================================================================================
//
//       Filename:  7568.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 22:04:53
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

int N, Nr[99][2];

int main() {
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> Nr[i][0] >> Nr[i][1];
	for(int i=0; i<N; i++)
	{
		int cnt = 1;
		for(int j=0; j<N; j++)
			if(Nr[j][0] > Nr[i][0] && Nr[j][1] > Nr[i][1])
				cnt++;
		cout << cnt << " ";
	}
	return 0;
}










