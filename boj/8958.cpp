// =====================================================================================
//
//       Filename:  8958.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 17:14:25
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
	int T; cin >> T;
	for(; T--;)
	{
		string S; cin >> S;
		int cnt = 0, sum = 0;
		for(char x : S)
		{
			if(x == 'O') cnt++;
			else cnt = 0;
			sum += cnt;
		}
		cout << sum << endl;
	}
	return 0;
}










