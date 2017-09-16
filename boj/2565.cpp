// =====================================================================================
//
//       Filename:  2568.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 17:50:51
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <algorithm>

#define pi pair<int, int>
#define fi first
#define se second

using namespace std;

const int MAX_N = 1e5;

bool cmp(pi A, pi B)
{
	return A.fi < B.fi;
}

int N;
pair<int, pi> L[MAX_N];
int Chk[MAX_N], Parent[MAX_N];
pi LS[MAX_N+1];


int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
	{
		scanf("%d%d", &L[i].fi, &L[i].se.fi);
		L[i].se.se = i;
	}
	sort(L, L+N);
	
	int cnt = 0;
	LS[0].se = -1;
	for(int i=0; i<N; i++)
	{
		int index = (int)(lower_bound(LS+1, LS+1+cnt, L[i].se, cmp) - LS);
		if(index > cnt) cnt++;
		LS[index] = L[i].se;
		Parent[LS[index].se] = LS[index-1].se;
	}

	int now = LS[cnt].se;
	while(now != -1)
		Chk[now] = 1, now = Parent[now];

	printf("%d", N - cnt);	

/*
	for(int i=0; i<N; i++)
		if(Chk[i] == 0)
			printf("\n%d", i+1);
*/
	return 0;
}















