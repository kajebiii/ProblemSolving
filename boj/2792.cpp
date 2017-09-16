// =====================================================================================
//
//       Filename:  2792.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/13/2016 22:20:41
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>

const int MAX_M = 3e5 + 10;

int N, M;
int Nr[MAX_M];

int main()
{
	scanf("%d%d", &N, &M);

	for(int i=0; i<M; i++)
		scanf("%d", &Nr[i]);

	int s = 1, e = 0x3fffffff, m;
	int ans = -1;
	while(s <= e)
	{
		m = (s + e) / 2;

		long long now = 0;
		for(int i=0; i<M; i++)
			now += (Nr[i] - 1) / m + 1;

		if(now <= N)
		{
			ans = m;
			e = m - 1;
		}
		else
			s = m + 1;
	}

	printf("%d\n", ans);

	return 0;
}
