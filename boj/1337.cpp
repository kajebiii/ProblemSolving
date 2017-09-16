//
//  main.cpp
//  1337
//
//  Created by KJBS2 on 03/07/2016.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

const int MAX_N = 1e4 + 10;

int N;
int Nr[MAX_N];

set<int> S;

int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++) 
	{
		scanf("%d", &Nr[i]);
		S.insert(Nr[i]);
	}

	int ans = 5;

	for(int i=0; i<N; i++)
	{
		int need = 0;
		for(int j=0; j<5; j++)
			if(S.count(Nr[i] + j) == 0)
				need++;
		ans = min(ans, need);
	}

	printf("%d", ans);

	return 0;
}

