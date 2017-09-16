// =====================================================================================
//
//       Filename:  2623.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 14:02:21
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 1e3 + 10;

int N, M;
int D[MAX_N];
vector<int> V[MAX_N];

int main()
{
	scanf("%d%d", &N, &M);

	for(int m=1; m<=M; m++)
	{
		int k; scanf("%d", &k);
		int first; scanf("%d", &first);
		for(int i=1; i<k; i++)
		{
			int last; scanf("%d", &last);
			V[first].push_back(last);
			D[last]++;
			first = last;
		}
	}

	vector<int> Ans;
	queue<int> Q;

	for(int i=1; i<=N; i++)
		if(D[i] == 0)
			Q.push(i);

	while(!Q.empty())
	{
		int now = Q.front(); Q.pop();
		Ans.push_back(now);
		for(int next : V[now])
			if(--D[next] == 0)
				Q.push(next);
	}

	if(Ans.size() == N)
	{
		for(int x : Ans)
			printf("%d\n", x);
	}
	else
		printf("0\n");

	return 0;
}










