// =====================================================================================
//
//       Filename:  10886.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/19/2016 10:31:41
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
	int sum = 0;
	for(int x, i=0; i<N; i++)
		cin >> x, sum += x;
	if((N+1)/2 <= sum)
		printf("Junhee is cute!\n");
	else
		printf("Junhee is not cute!\n");
	return 0;
}










