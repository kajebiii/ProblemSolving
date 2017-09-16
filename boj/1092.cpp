//
//  main.cpp
//  1092
//
//  Created by KJBS2 on 03/07/2016.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

const int INF = 0x7fffffff;

int N, M;
int C[99];
int B[11111];

int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", &C[i]);
	scanf("%d", &M);
	for(int i=0; i<M; i++)
		scanf("%d", &B[i]);


	sort(C, C+N, greater<int>());
	sort(B, B+M, greater<int>());

	int days = 0;
	int boxes = 0;
	while(boxes < M)
	{
		int last = boxes;
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<M; j++)
				if(C[i] >= B[j])
				{
					boxes++;
					B[j] = INF;
				   	break;	
				}
		}

		if(last == boxes) 
		{
			printf("-1\n");
			return 0;
		}
		days++;
	}

	printf("%d\n", days);
		

	return 0;
}
