// =====================================================================================
//
//       Filename:  1920.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 16:52:36
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

int N;
set<int> S;
int main() {
	cin >> N;
	for(; N--;)
	{
		int x; scanf("%d", &x);
		S.insert(x);
	}
	cin >> N;
	for(; N--;)
	{
		int x; scanf("%d", &x);
		if(S.count(x) == 0)
			printf("0\n");
		else
			printf("1\n");
	}
	return 0;
}










