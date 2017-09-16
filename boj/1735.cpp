// =====================================================================================
//
//       Filename:  1735.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 17:40:21
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

int gcd(int a, int b)
{
	return a == 0 ? b : gcd(b%a, a);
}

int main() {
	int A, B, C, D; cin >> A >> B >> C >> D;
	int E = A*D + B*C, F = B*D;
	cout << E / gcd(E,F) << " " << F / gcd(E,F);
	return 0;
}










