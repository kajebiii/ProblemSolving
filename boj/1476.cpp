// =====================================================================================
//
//       Filename:  1476.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 21:39:33
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
	cout << (((A-1)*28*19*(13) + (B-1)*15*19*(17) + (C-1)*15*28*(10)))%(28*19*15)+1;
	return 0;
}










