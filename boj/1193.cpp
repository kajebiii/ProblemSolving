// =====================================================================================
//
//       Filename:  1193.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 20:10:45
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
	int K; cin >> K;
	for(int i=1; i<=10000; i++)
	{
		if(K > i) K -= i;
		else
		{
			if(i % 2 == 0)
				printf("%d/%d\n", K, i+1-K);
			else
				printf("%d/%d\n", i+1-K, K);
			break;
		}
	}
	return 0;
}










