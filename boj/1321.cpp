//
//  main.cpp
//  1321
//
//  Created by KJBS2 on 03/07/2016.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

const int MAX_N = 5e5 + 10;

int N, P, T[MAX_N * 3];


void Up(int v, int k)
{
	T[v] = k;
	while(v /= 2)
		T[v] = T[v*2] + T[v*2 + 1];
}

int getSum(int a, int b)
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
	scanf("%d", &N);
	for(P=1; P<N; P<<=1);

	for(int i=0; i<N; i++)
	{
		int x; scanf("%d", &x);
		Up(P+i, x);
	}

	int M; scanf("%d", &M);
	for(; M--; )
	{
		int k; scanf("%d", &k);
		if(k == 1)
		{
			int v, x;
			scanf("%d%d", &v, &x);
			Up(P+v-1, T[P+v-1] + x);

//			for(int i=0; i<N; i++)
//				printf("[%d -> %d]\n", i, T[P+i]);
		}
		if(k == 2)
		{
			int x;
			scanf("%d", &x);

			int s = 0, e = N, m;
			int result = -1;
			while(s <= e)
			{
				m = (s + e) / 2;
				int sum = getSum(P + 0, P + m - 1);
					
//				printf("find [%d] : m = %d -> sum = %d\n", x, m, sum);

				if(sum >= x)
					e = m-1;
				else
				{
					result = m;
					s = m+1;
				}
			}

			printf("%d\n", result + 1);
		}
	}

	return 0;
}







