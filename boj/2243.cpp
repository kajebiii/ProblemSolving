// =====================================================================================
//
//       Filename:  2243.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/12/2016 19:29:24
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>

const int MAX_C = 1e6 + 10;

int T[MAX_C * 3], P;

void Up(int v, int k)
{
	T[v] = k;
	while(v/=2)
		T[v] = T[v*2] + T[v*2+1];
	return;
}

int Get(int a, int b)
{
	int result = 0;
	while(a <= b)
	{
		if(a%2 == 1) result += T[a++];
		if(b%2 == 0) result += T[b--];
		a/=2; b/=2;
	}

	return result;
}

int main()
{
	int N;
	scanf("%d", &N);
	for(P=1; P<(int)(1e6); P<<=1);
	for(; N--; )
	{
		int a, b, c;
		scanf("%d", &a);
		if(a == 1)
		{
			scanf("%d", &b);
			int s = 0, e = (int)(1e6), m;
			int ans = -1;
			while(s <= e)
			{
				m = (s + e) / 2;
				if(Get(P+1-1, P+m-1) < b)
				{
					ans = m;
					s = m + 1;
				}
				else
					e = m - 1;
			}
			Up(P + ans + 1 - 1, T[P + ans + 1 - 1] - 1);
			printf("%d\n", ans + 1);
		}
		else
		{
			scanf("%d%d", &b, &c);
			Up(P + b - 1, T[P + b - 1] + c);
		}
	}
}



















