// =====================================================================================
//
//       Filename:  3344.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/24/2016 00:04:03
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


int main() {
	int N;
	cin >> N;
	bool odd = false;
	if(N % 2 == 1)
	{
		odd = true;
		N = N - 1;
	}
	if(N % 6 != 2)
	{
		for(int i=1; i<=N/2; i++)
			printf("%d\n", i*2);
		for(int i=1; i<=N/2; i++)
			printf("%d\n", i*2-1);
	}
	else
	{
		int now = N / 2;
		for(int i=1; i<=N/2; i++, now+=2, now = (now-1)%N + 1)
			printf("%d\n", now);
		now = N - (N / 2 - 3 + N) % N;	
		for(int i=1; i<=N/2; i++, now+=2, now = (now-1)%N + 1)
			printf("%d\n", now);
	}
	if(odd)
		printf("%d\n", N+1);
	return 0;
}










