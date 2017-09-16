// =====================================================================================
//
//       Filename:  1292.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/16/2016 22:03:37
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

#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

int Nr[1111];

int main() {
	int A, B; cin >> A >> B;
	int cnt = 0;
	for(int i=1; i<=100; i++)
		for(int j=1; j<=i; j++)
			if(cnt < 1010) 
				Nr[++cnt] = i;
	int result = 0;
	for(int i=A; i<=B; i++)
		result += Nr[i];
	printf("%d\n", result);
	return 0;
}










