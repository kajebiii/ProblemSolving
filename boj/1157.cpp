// =====================================================================================
//
//       Filename:  1157.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 17:55:41
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

int A[200];

int main() {
	string S; cin >> S;
	transform(S.begin(), S.end(), S.begin(), ::toupper);
	char x; int c = 0, same = 0;
	for(char k : S)
	{
		A[k]++;
		if(c == A[k])
		{
			same++;
		}
		if(c < A[k])
		{
			x = k;
			c = A[k];
			same = 1;
		}
	}
	if(same > 1)
		printf("?\n");
	else
		cout << x;
	return 0;
}










