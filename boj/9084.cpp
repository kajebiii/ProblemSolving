// =====================================================================================
//
//       Filename:  2293.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/16/2016 23:56:25
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

const int INF = 0x7fffffff;

int Dy[100001];

int main() {

	int T; cin >> T;
	for(; T--; )
	{
		int N, K = 10000; cin >> N;

		for(int i=0; i<=K; i++)
			Dy[i] = 0;
		Dy[0] = 1;
		for(; N--; )
		{
			int x; cin >> x;
			for(int i=0; i<=K-x; i++)
				Dy[i+x] = Dy[i+x] + Dy[i];
		}
		cin >> K;
		printf("%d\n", Dy[K]);
	}
	return 0;
}










