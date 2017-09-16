// =====================================================================================
//
//       Filename:  10453.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/15/2016 12:42:11
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

int N;
string S;
priority_queue<int, vector<int>, greater<int> > Q[2];
int main()
{
	int T; scanf("%d", &T);

	for(; T--; )
	{
		cin >> S;

		int cnt = 0;
		for(char x : S)
			Q[x-'a'].push(cnt++);

		cin >> S;

		cnt = 0;

		long long result = 0;
		for(char x : S)
		{
			while(Q[x-'a'].top() < cnt) Q[x-'a'].pop();
			result += 1ll * (Q[x-'a'].top() - cnt);
			Q[1-x+'a'].push(Q[x-'a'].top());
			Q[x-'a'].pop();
			cnt++;
		}

		printf("%lld\n", result);

		for(int i=0; i<2; i++)
			while(!Q[i].empty())
				Q[i].pop();
	}

	return 0;
}

















