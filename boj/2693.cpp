// =====================================================================================
//
//       Filename:  2693.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/22/2016 00:09:35
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
	int N; cin >> N;
	for(; N--; )
	{
		int A[10]; for(int i=0; i<10; i++) scanf("%d", &A[i]);
		sort(A, A+10);
		printf("%d\n", A[10-3]);
	}
	return 0;
}










