//
//  main.cpp
//  1037
//
//  Created by KJBS2 on 03/13/2016.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 50;

int N;
int Divisor[MAX_N];

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &Divisor[i]);
	sort(Divisor, Divisor + N);

	printf("%lld", 1ll * Divisor[0] * Divisor[N-1]);

	return 0;
}