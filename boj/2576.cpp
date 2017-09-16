// =====================================================================================
//
//       Filename:  2576.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/16/2016 23:51:52
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
	int A[7], cnt = 0;
	for(int i=0; i<7; i++)
	{
		int x; cin >> x;
		if(x % 2 == 1)
			A[cnt++] = x;
	}
	if(cnt == 0)
		printf("-1");
	else
	{
		sort(A, A+cnt);
		printf("%d\n%d\n", accumulate(A, A+cnt, 0), A[0]);
	}
	return 0;
}










