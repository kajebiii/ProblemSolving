// =====================================================================================
//
//       Filename:  5063.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/22/2016 18:13:08
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

int main() {
	int N; cin >> N;
	for(;N--;)
	{
		int A, B, C;
		scanf("%d%d%d", &A, &B, &C);
		if(A + C > B)
			puts("do not advertise");
		else if(A + C == B)
			puts("does not matter");
		else
			puts("advertise");
	}
	return 0;
}










