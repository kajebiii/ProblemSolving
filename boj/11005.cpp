// =====================================================================================
//
//       Filename:  11005.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/26/2016 13:19:25
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

void Print(int k)
{
	if(k < 10) cout << k;
	else printf("%c", 'A' + k - 10);
}
void Ans(int n, int z)
{
	if(n == 0) return;
	Ans(n/z, z);
	Print(n % z);
}

int main() {
	int N, Z; cin >> N >> Z;
	Ans(N, Z);
	return 0;
}










