// =====================================================================================
//
//       Filename:  10872.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 22:07:42
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
	int Ans = 1;
	for(int i=1; i<=N; i++)
		Ans *= i;
	cout << Ans;
	return 0;
}










