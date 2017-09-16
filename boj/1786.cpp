// =====================================================================================
//
//       Filename:  1786.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/14/2016 01:35:33
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

const int MAX_N = 1e6 + 30;

int N, M;
char A[MAX_N], S[MAX_N];
int F[MAX_N];

int main()
{
	cin.getline(A, MAX_N);
	cin.getline(S, MAX_N);
	N = (int)strlen(A);
	M = (int)strlen(S);

	int i, j;
	for(F[i=0]=j=-1; i<M; j<0||S[i]==S[j]?F[++i]=++j:j=F[j]);

	i = 0, j = 0;
	vector<int> Ans;
	for(i=j=0; i<N; )
		if(j<0 || A[i] == S[j])
		{
			if(++i && ++j == M)
				Ans.push_back(i-j+1);
		}
		else
			j = F[j];
	
	printf("%d\n", (int)Ans.size());
	for(int i=0; i<(int)Ans.size(); i++)
		printf("%d ", Ans[i]);
	return 0;
}










