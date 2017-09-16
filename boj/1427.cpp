// =====================================================================================
//
//       Filename:  1427.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/16/2016 23:33:58
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
	int A[20];
	int cnt = 0;
	while(scanf("%1d", &A[cnt++]) != EOF);
	cnt--;
	sort(A, A+cnt);

	for(int i=cnt-1; i>=0; i--)
		printf("%d", A[i]);
	return 0;
}










