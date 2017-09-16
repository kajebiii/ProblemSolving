// =====================================================================================
//
//       Filename:  7575.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/14/2016 02:46:12
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <vector>

using namespace std;

const int MAX_N = 111;
const int MAX_K = 1111;

int N, K;
vector<int> V[MAX_N];
int S[MAX_K];
int F[MAX_K];

bool isVirus()
{
	for(int k=1; k<N; k++)
	{
		int n = (int)V[k].size();

		bool nowTrue = false;
		for(int i=0, j=0; i < n; )
			if(j < 0 || V[k][i] == S[j])
			{
				if(++i && ++j == K)
					nowTrue = true;
			}
			else
				j = F[j];
		for(int i=0, j=0; i < n; )
			if(j < 0 || V[k][n-1-i] == S[j])
			{
				if(++i && ++j == K)
					nowTrue = true;
			}
			else
				j = F[j];

		if(nowTrue == false)
			return false;
	}
	return true;
}

int main()
{
	scanf("%d%d", &N, &K);
	for(int x, i=0; i<N; i++)
	{
		scanf("%d", &x);
		for(int y; x--; scanf("%d", &y), V[i].push_back(y));
	}
	
	int n = (int)V[0].size();
	for(int i=0; i<n; i++)
	{
		if(i + K < n)
		{
			for(int j=0; j<K; j++) S[j] = V[0][i+j];
			int s, e;
			for(F[s=0]=e=-1; s<K; e<0 || S[s]==S[e] ? F[++s]=++e : e = F[e]);
			if(isVirus())
			{
				printf("YES\n");
				return 0;
			}
		}
		if(i >= K - 1)
		{
			for(int j=0; j<K; j++) S[j] = V[0][i-j];
			int s, e;
			for(F[s=0]=e=-1; s<K; e<0 || S[s]==S[e] ? F[++s]=++e : e = F[e]);
			if(isVirus())
			{
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}




















