// =====================================================================================
//
//       Filename:  1225.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/27/2016 22:44:51
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

long long get(string S)
{
	long long result = 0;
	for(char x : S)
		result += 1ll * (x - '0');
	return result;
}

int main() {
	string A, B; cin >> A >> B;
	printf("%lld", get(A) * get(B));
	return 0;
}










