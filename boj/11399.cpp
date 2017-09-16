// =====================================================================================
//
//       Filename:  11399.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 23:27:11
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

int N, Nr[1111];

int main() {
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> Nr[i];
	sort(Nr, Nr+N);

	int result = 0;
	for(int i=0; i<N; i++)
		result += ((N-i) * Nr[i]);
	cout << result;
	return 0;
}










