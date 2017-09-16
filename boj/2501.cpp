// =====================================================================================
//
//       Filename:  2501.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 17:30:47
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
	vector<int> V;
	int N, K; cin >> N >> K;
	for(int i=1; i*i<=N; i++)
		if(N % i == 0)
		{
			if((i*i) != N)
				V.push_back(N/i);
			V.push_back(i);
		}
	sort(V.begin(), V.end());
	if(K > V.size())
		printf("0\n");
	else
		cout << V[K-1];
	return 0;
}










