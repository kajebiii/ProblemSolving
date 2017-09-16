// =====================================================================================
//
//       Filename:  11052.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/19/2016 09:35:22
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

const int MAX_N = 1e3 + 10;

int N, Dy[MAX_N];

int main() {
	cin >> N;
	for(int i=1; i<=N; i++)
	{
		int x; scanf("%d", &x);
		for(int j=0; j<=N-i; j++)
			Dy[j+i] = max(Dy[j+i], Dy[j] + x);
	}
	cout << Dy[N];
	return 0;
}










