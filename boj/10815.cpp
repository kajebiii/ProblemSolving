// =====================================================================================
//
//       Filename:  10815.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/21/2016 16:52:12
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

set<int> S;

int main() {
	int N; scanf("%d", &N);
	for(int x; N--; )
		scanf("%d", &x), S.insert(x);
	int M; scanf("%d", &M);
	for(int x; M--;)
		scanf("%d", &x), printf("%d ", (int)S.count(x));
	return 0;
}










