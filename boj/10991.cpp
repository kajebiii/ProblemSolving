// =====================================================================================
//
//       Filename:  10991.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/21/2016 16:54:13
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

int main() {
	int N; cin >> N;
	for(int i=N-1; i>=0; i--)
	{
		for(int j=0; j<i; j++) printf(" ");
		for(int j=0; j<N-i; j++) printf("* ");
		printf("\n");
	}
	return 0;
}










