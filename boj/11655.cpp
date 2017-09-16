// =====================================================================================
//
//       Filename:  11655.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/21/2016 16:48:56
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

char change(char x)
{
	if(x >= 'A' && x <= 'Z')
		return (x - 'A' + 13) % 26 + 'A';
	if(x >= 'a' && x <= 'z')
		return (x - 'a' + 13) % 26 + 'a';
	return x;
}

int main() {
	string S;
	getline(cin, S);
	for(auto x : S)
		cout << change(x);
	return 0;
}










