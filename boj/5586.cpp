// =====================================================================================
//
//       Filename:  5586.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/26/2016 13:14:13
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
	string S; cin >> S;
	int J=0, I=0;
	for(int i=2; i<S.length(); i++)
		if(S[i-1] == 'O' && S[i] == 'I')
		{
			if(S[i-2] == 'I') I++;
			if(S[i-2] == 'J') J++;
		}
	cout << J << endl << I;
	return 0;
}










