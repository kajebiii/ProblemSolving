// =====================================================================================
//
//       Filename:  1316.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/27/2016 14:29:17
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
	int ans = 0;
	for(int t=1; t<=T; t++)
	{
		string S; cin >> S;
		Chk[S[0]] = t;
		bool flag = true;
		for(int i=1; i<S.length(); i++)
		{
			if(Chk[S[i]] == t)
			{
				if(S[i] != S[i-1])
				{
					flag = false;
					break;
				}
			}
			else
				Chk[S[i]] = t;
		}
		if(flag) ans++;
	}
	cout << ans;
	return 0;
}










