// =====================================================================================
//
//       Filename:  3003.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/19/2016 09:59:30
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
	int A[6] = {1, 1, 2, 2, 2, 8};
	for(int i=0; i<6; i++)
	{
		int x; cin >> x;
		cout << A[i] - x << " ";
	}
	return 0;
}










