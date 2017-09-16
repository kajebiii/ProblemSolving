// =====================================================================================
//
//       Filename:  2711.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/21/2016 16:46:11
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
	int N; scanf("%d", &N);
	for(; N--;)
	{
		int x; scanf("%d", &x);
		string S; cin >> S;
		for(int i=0; i<S.length(); i++)
			if(i+1 != x)
				printf("%c", S[i]);
		printf("\n");
	}
	return 0;
}










