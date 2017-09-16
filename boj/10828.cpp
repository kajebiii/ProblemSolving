// =====================================================================================
//
//       Filename:  10828.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/16/2016 22:41:14
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

#include <stack>

int main() {
	stack<int> S;
	int T; cin >> T;
	for(; T--;)
	{
		string K; cin >> K;
		if(K == "push")
		{
			int x; cin >> x;
			S.push(x);
		}
		if(K == "pop")
		{
			if(S.empty())
				printf("-1\n");
			else
				printf("%d\n", S.top()), S.pop();
		}
		if(K == "size")
			printf("%d\n", (int)S.size());
		if(K == "empty")
			printf("%d\n", (int)S.empty());
		if(K == "top")
		{
			if(S.empty())
				printf("-1\n");
			else
				printf("%d\n", S.top());
		}
	}
	return 0;
}










