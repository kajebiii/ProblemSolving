// =====================================================================================
//
//       Filename:  10818.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 16:50:43
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

int N, Nr[1111111];

int main() {
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> Nr[i];
	cout << Nr[min_element(Nr, Nr+N) - Nr] << " " << Nr[max_element(Nr, Nr+N) - Nr] << endl;
	return 0;
}










