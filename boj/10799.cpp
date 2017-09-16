// =====================================================================================
//
//       Filename:  10799.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 22:13:49
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

int main() {
	string S; cin >> S;

	int cnt = 0, ans = 0;
	for(int i=0; i<S.size(); i++)
	{
		if(S[i] == '(')
			cnt++, ans++;
		else
		{
			cnt--;
			if(S[i-1] == '(')
			{
				ans += cnt;
				ans -= 1;
			}
		}
	}
	cout << ans;
	return 0;
}










