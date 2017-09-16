// =====================================================================================
//
//       Filename:  10845.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 23:18:13
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
	deque<int> Q;
	for(; T--;)
	{
		string S; cin >> S;
		if(S == "push")
		{
			int x; cin >> x;
			Q.push_back(x);
		}
		if(S == "pop")
		{
			if(Q.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", Q.front());
				Q.pop_front();
			}
		}
		if(S == "size")
			printf("%d\n", (int)Q.size());
		if(S == "empty")
			printf("%d\n", (int)Q.empty());
		if(S == "front")
		{
			if(Q.empty())
				printf("-1\n");
			else
				printf("%d\n", Q.front());
		}
		if(S == "back")
		{
			if(Q.empty())
				printf("-1\n");
			else
				printf("%d\n", Q.back());
		}		
	}
	return 0;
}










