// =====================================================================================
//
//       Filename:  11722.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 15:13:11
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

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};

int A[1111], AN, Nr[1111];
int main() {
	int N; cin >> N;
	for(int i=0; i<N; i++) scanf("%d", &Nr[N-i-1]);
	for(int i=0; i<N; i++)
	{
		int index = lower_bound(A, A+AN, Nr[i]) - A;
		if(index == AN)
			AN++;
		A[index] = Nr[i];
	}
	cout << AN;
	return 0;
}










