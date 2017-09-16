//
//  main.cpp
//  1026
//
//  Created by KJBS2 on 03/01/2016.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 99;

int N;
int Nr[2][MAX_N];

int main() {
	scanf("%d", &N);
	for(int k = 0; k < 2; k++) for(int i = 0; i < N; i++)
		scanf("%d", &Nr[k][i]);
	for(int k = 0; k < 2; k++)
		sort(Nr[k], Nr[k] + N);

	int Answer = 0;
	for(int i = 0; i < N; i++)
		Answer += Nr[0][i] * Nr[1][N-1-i];

	printf("%d", Answer);

	return 0;
}






