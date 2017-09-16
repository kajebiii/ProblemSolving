// =====================================================================================
//
//       Filename:  3059.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/26/2016 13:27:09
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

int Chk[999];
int main() {
	int T; cin >> T;
	while(T--)
	{
		string S; cin >> S;
		for(int i='A'; i<='Z'; i++)
			Chk[i] = 0;
		for(char x : S)
			Chk[x] = 1;

		int sum = 0;
		for(int i='A'; i<='Z'; i++)
			if(Chk[i] == 0)
				sum += i;
		printf("%d\n", sum);
	}
	return 0;
}










