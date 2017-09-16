// =====================================================================================
//
//       Filename:  9661.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/21/2016 15:53:07
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


int main() {
	long long N; scanf("%lld", &N);
	if(N % 5 == 0 || N % 5 == 2)
		printf("CY\n");
	else
		printf("SK\n");
	return 0;
}