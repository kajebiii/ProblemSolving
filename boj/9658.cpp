// =====================================================================================
//
//       Filename:  9658.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/21/2016 15:13:03
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
	int N; scanf("%d", &N);
	if(N % 7 == 1 || N % 7 == 3)
		printf("CY");
	else
		printf("SK");
	return 0;
}










