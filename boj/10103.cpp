// =====================================================================================
//
//       Filename:  10103.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/22/2016 17:52:58
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
	int A, B; A = B = 100;
	for(; N--;)
	{
		int a, b; cin >> a >> b;
		if(a < b) A -= b;
		if(a > b) B -= a;
	}
	cout << A << endl << B;
	return 0;
}










