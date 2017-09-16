// =====================================================================================
//
//       Filename:  2857.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 16:52:39
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
#include <math.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};

int main() {
	bool have = false;
	for(int i=1; i<=5; i++)
	{
		string S; cin >> S;
		bool yes = false;
		for(int j=2; j<S.length(); j++)
			if(S[j-2]=='F' && S[j-1]=='B' && S[j]=='I')
				yes = true;
		if(yes)
		{
			have = true;
			printf("%d ", i);
		}
	}
	if(have == false) 
		puts("HE GOT AWAY!");
	return 0;
}










