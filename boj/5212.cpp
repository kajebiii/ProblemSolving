// =====================================================================================
//
//       Filename:  5212.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/14/2016 00:26:46
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <algorithm>

using namespace std;

int R, C;
char Map[30][30];
char Ans[30][30];

int main()
{
	scanf("%d%d", &R, &C);

	for(int i=1; i<=R; i++)
		scanf("%s", Map[i] + 1);
	for(int i=0; i<=R+1; i++)
		Map[i][0] = Map[i][C+1] = '.';
	for(int i=0; i<=C+1; i++)
		Map[0][i] = Map[R+1][i] = '.';
	
	int mi = R, Mi = 1, mj = C, Mj = 1;
	for(int i=1; i<=R; i++)
		for(int j=1; j<=C; j++)
		{
			Ans[i][j] = '.';
			if(Map[i][j] == '.')
				continue;
			int Cx[4] = {0, 1, 0, -1};
			int Cy[4] = {1, 0, -1, 0};

			int cnt = 0;
			for(int k=0; k<4; k++)
				cnt += (Map[i+Cx[k]][j+Cy[k]] == '.');
			if(cnt <= 2)
			{
				Ans[i][j] = 'X';
				mi = min(mi, i);
				Mi = max(Mi, i);
				mj = min(mj, j);
				Mj = max(Mj, j);
			}	
		}
	
	for(int i=mi; i<=Mi; i++, printf("\n"))
		for(int j=mj; j<=Mj; j++, printf("%c", Ans[i][j-1]));

	return 0;
}
