// =====================================================================================
//
//       Filename:  5218.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 14:19:36
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
	int T; cin >> T;
	for(; T--;)
	{
		string S[2]; cin >> S[0] >> S[1];
		printf("Distances:");
		for(int i=0; i<S[0].length(); i++)
			cout << " " <<  (S[1][i] - S[0][i] + 26)%26;
		printf("\n");
	}
	return 0;
}










