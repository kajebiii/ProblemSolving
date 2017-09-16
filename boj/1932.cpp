// =====================================================================================
//
//       Filename:  1932.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 21:18:24
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

using namespace std;

const int MAX_N = 999;

int Nr[MAX_N][MAX_N];
int N;

int main() {
	cin >> N;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=i; j++)
		{
			cin >> Nr[i][j];
			Nr[i][j] += max(Nr[i-1][j-1], Nr[i-1][j]);
		}
	printf("%d\n", Nr[N][max_element(Nr[N] + 1, Nr[N] + N + 1) - Nr[N]]);
	return 0;
}










