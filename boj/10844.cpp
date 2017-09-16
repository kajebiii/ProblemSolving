// =====================================================================================
//
//       Filename:  10844.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/19/2016 11:42:58
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

const int MAX_N = 1e2 + 11;
const int MOD = 1e9;

int Dy[MAX_N][10], N;

int main() {
	cin >> N;
	for(int i=1; i<10; i++)
		Dy[1][i] = 1;
	for(int i=2; i<=N; i++)
	{
		for(int j=0; j<9; j++)
			Dy[i][j] += Dy[i-1][j+1], Dy[i][j] %= MOD;
		for(int j=1; j<10; j++)
			Dy[i][j] += Dy[i-1][j-1], Dy[i][j] %= MOD;
	}
	int sum = 0;
	for(int i=0; i<10; i++)
		sum += Dy[N][i], sum %= MOD;
	cout << sum;
	return 0;
}










