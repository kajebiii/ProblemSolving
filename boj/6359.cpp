// =====================================================================================
//
//       Filename:  6359.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 14:35:12
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

int D[111];

int main() {
	int T; cin >> T;
	for(int i=1; i<=10; i++)
		D[i*i] = 1;
	for(int i=1; i<=100; i++)
		D[i] += D[i-1];

	for(; T--;)
	{
		int N; cin >> N;
		cout << D[N] << endl;
	}
	return 0;
}










