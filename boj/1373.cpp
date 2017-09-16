// =====================================================================================
//
//       Filename:  1373.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/19/2016 14:08:21
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


int main() {
	string S; cin >> S;
	int N = S.length();
	if(N % 3 == 1)
		S = "00" + S, N+=2;
	if(N % 3 == 2)
		S =  "0" + S, N+=1;
	for(int i=0; i<N; i+=3)
	{
		int x = 0;
		for(int j=0; j<3; j++)
			x *= 2, x += (S[i+j] - '0');
		printf("%o", x);
	}
	return 0;
}










