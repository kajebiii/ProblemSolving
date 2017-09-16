//

//  main.cpp
//  1068
//
//  Created by KJBS2 on 03/07/2016.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>

const int MAX_N = 99;

int N, Parent[MAX_N];
int Root = -1;
int SumLeaf[MAX_N];
int Count[MAX_N];

int main()
{
	scanf("%d", &N);
	
	for(int i=0; i<N; i++)
	{
		scanf("%d", &Parent[i]);
		if(Parent[i] == -1)
			Root = i;
		else
			Count[Parent[i]]++;
	}

	for(int i=0; i<N; i++)
	{
		if(Count[i] == 0)
		{
			int now = i;
			while(now != -1)
			{
				SumLeaf[now]++;
				now = Parent[now];
			}
		}
	}
	
	int deleteNode = -1;
	scanf("%d", &deleteNode);
	
	int plus = 0;
	if(Parent[deleteNode] != -1 && Count[Parent[deleteNode]] == 1)
		plus = 1;
	printf("%d", SumLeaf[Root] - SumLeaf[deleteNode] + plus);

	return 0;
}



