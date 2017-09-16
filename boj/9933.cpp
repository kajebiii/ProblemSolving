// =====================================================================================
//
//       Filename:  9933.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 21:12:53
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

string S[111];
int main() {
	int N; cin >> N;
	for(int i=0; i<N; i++) cin >> S[i];
	for(int i=0; i<N; i++) for(int j=i; j<N; j++)
	{
		if(S[i].length() != S[j].length()) continue;
		bool same = true;
		for(int k=0; k<S[i].length(); k++)
			if(S[i][k] != S[j][S[i].length()-1-k])
				same = false;
		if(same)
		{
			printf("%d %c", (int)S[i].length(), S[i][(int)S[i].length()/2]);
			break;
		}
	}
	return 0;
}










