// =====================================================================================
//
//       Filename:  11047.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 00:10:21
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
	int N, K; cin >> N >> K;
	int A[20];
	for(int i=1; i<=N; i++)
		cin >> A[i];
	
	int result = 0;
	for(int i=N; i>=1; i--)
	{
		result += K / A[i];
		K %= A[i];
	}
	cout << result;
	return 0;
}










