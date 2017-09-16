// =====================================================================================
//
//       Filename:  2530.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/16/2016 23:43:12
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
	int A, B, C; cin >> A >> B >> C;
	int D; cin >> D;
	C += D;
	B += C / 60; C %= 60;
	A += B / 60; B %= 60;
	A %= 24;
	printf("%d %d %d\n", A, B, C);
	return 0;
}










