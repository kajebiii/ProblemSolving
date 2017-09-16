//
//  main.cpp
//  1024
//
//  Created by KJBS2 on 03/01/2016.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>

int S, L;

int main() {
	scanf("%d%d", &S, &L);
	for(int m=L; m<=100; m++) {
		if(S*2%m != 0) continue;
		int N = (S*2/m + 1 - m) % 2 == 0 ? (S*2/m + 1 - m) / 2 : -1;
		if(N < 0) continue;
		for(int i=0; i<m; i++)
			printf("%d ", N+i);
		return 0;
	}
	printf("-1");
	return 0;
}