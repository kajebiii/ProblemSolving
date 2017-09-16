// =====================================================================================
//
//       Filename:  9012.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/16/2016 22:28:36
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

#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

int main() {
	int T; cin >> T;
	for(; T--;)
	{
		string S; cin >> S;
		int sum = 0, chk = 0;
		for(char x : S)
		{
			if(x == '(') sum++;
			else sum--;
			chk = min(chk, sum);
		}
		if(chk < 0 || sum != 0) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}









