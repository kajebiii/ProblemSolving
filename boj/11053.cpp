// =====================================================================================
//
//       Filename:  12738.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/19/2016 09:18:08
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

const int MAX_N = 1e6 + 1000;

int N, A[MAX_N], AN;

int main() {
	cin >> N;
	for(int i=0; i<N; i++)
	{
		int x; scanf("%d", &x);
		int index = (int)(lower_bound(A, A + AN, x) - A);
		if(index == AN)
			AN++;
		A[index] = x;
	}
	printf("%d\n", AN);
	return 0;
}










