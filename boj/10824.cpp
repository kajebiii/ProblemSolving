// =====================================================================================
//
//       Filename:  10824.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 17:19:49
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
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};

int main() {
	long long A, B, C, D; cin >> A >> B >> C >> D;
	long long AA = B, CC = D;
	while(B) 
		A *= 10, B /= 10;
	AA += A;
	while(D)
		C *= 10, D /= 10;
	CC += C;
	cout << AA + CC;
	return 0;
}










