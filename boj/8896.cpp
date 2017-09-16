// =====================================================================================
//
//       Filename:  8896.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 01:51:04
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int N, K;
int W[20][40];

int Chg(char x)
{
	if(x == 'S') return 0;
	if(x == 'R') return 1;
	return 2;
}

int main()
{
	int T; scanf("%d", &T);
	for(; T--; )
	{
		scanf("%d", &N);
		for(int i=1; i<=N; i++)
		{
			char S[40];
			scanf("%s", S + 1);
			K = (int)strlen(S + 1);

			for(int j=1; j<=K; j++)
				W[i][j] = Chg(S[j]);
		}

		vector<int> V[2];
		for(int i=1; i<=N; i++)
			V[0].push_back(i);
		
		bool flag = false;
		for(int j=1; j<=K; j++)
		{
			V[j%2].clear();
			vector<int> T[3];
			for(int x : V[1-j%2])
				T[W[x][j]].push_back(x);
			int n[3] = {(int)(T[0].size()), (int)(T[1].size()), (int)(T[2].size())};
			if((n[0] > 0 && n[1] > 0 && n[2] > 0) || (n[0] + n[1]) == 0 || (n[1] + n[2]) == 0 || (n[2] + n[0]) == 0)
				for(int x : V[1-j%2])
					V[j%2].push_back(x);
			else
				for(int i=0; i<3; i++)
					if(n[i] == 0)
						for(int x : T[(i+2)%3])
							V[j%2].push_back(x);
			if(V[j%2].size() == 1)
			{
				flag = true;
				printf("%d\n", V[j%2][0]);
				break;
			}
		}
		if(flag) continue;
		printf("0\n");
	}

	return 0;
}
















