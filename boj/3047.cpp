// =====================================================================================
//
//       Filename:  3047.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/22/2016 00:35:26
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
	int A[3]; for(int i=0; i<3; i++) cin >> A[i];
	sort(A, A+3);
	string AA; cin >> AA;
	for(char x : AA)
		for(int i=0; i<3; i++)
			if('A' + i == x)
				cout << A[i] << " ";
	return 0;
}










