// =====================================================================================
//
//       Filename:  10807.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/22/2016 17:43:09
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

int Chk[333];

int main() {
	int N; cin >> N;
	for(int i=0; i<N; i++)
	{
		int x; scanf("%d", &x);
		Chk[x + 100] ++;
	}
	int v; cin >> v;
	cout << Chk[v + 100];
	return 0;
}










