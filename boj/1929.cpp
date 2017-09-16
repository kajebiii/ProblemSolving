// =====================================================================================
//
//       Filename:  1929.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 22:26:51
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

bool isPrime[1111111];

int main() {
	int M, N; cin >> M >> N;
	for(int i=2; i<=N; i++)
	{
		if(isPrime[i]) continue;
		for(int j=i*2; j<=N; j+=i) isPrime[j] = true;
		if(i >= M)
			printf("%d\n", i);
	}
	return 0;
}










