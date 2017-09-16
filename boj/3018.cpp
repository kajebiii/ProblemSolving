// =====================================================================================
//
//       Filename:  3018.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/13/2016 22:42:41
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

const int MAX_N = 1e2 + 10;
const int MAX_E = 5e1 + 10;

int N, E, S;
bool Know[MAX_N][MAX_E];
int Chk[MAX_N];

int main()
{
	scanf("%d%d", &N, &E);

	for(int i=1; i<=E; i++)
	{
		vector<int> V;
		int k; scanf("%d", &k);
		for(int x; k--; scanf("%d", &x), V.push_back(x), Chk[x] = i);

		if(Chk[1] == i)
		{
			++S;
			for(int x : V)
				Know[x][S] = true;
		}
		else
		{
			vector<bool> Info = vector<bool>(S+1, false);
			for(int x : V)
				for(int k=1; k<=S; k++)
					if(Know[x][k] == true)
						Info[k] = true;
			for(int x : V)
				for(int k=1; k<=S; k++)
					if(Info[k] == true)
						Know[x][k] = true;
			Info.shrink_to_fit();
		}
		V.shrink_to_fit();
	}

	for(int i=1; i<=N; i++)
	{
		bool flag = true;
		for(int j=1; j<=S; j++)
			if(Know[i][j] == false)
				flag = false;
		if(flag)
			printf("%d\n", i);
	}

	return 0;
}










