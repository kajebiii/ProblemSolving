//
//  main.cpp
//  1023
//
//  Created by KJBS2 on 03/01/2016.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>

const int MAX_N = 99;

int N;
long long K;
long long Count[MAX_N][MAX_N];

long long NoNoCount(int n, int h) {
	if(h < 0) return 1ll << (N-n);
	return (1ll << (N-n)) - Count[n][h];
}

int main() {
	scanf("%d%lld", &N, &K);
	K += 1;

	Count[N][0] = 1;
	for(int i=N-1; i>=0; i--) {
		for(int j=0; j<=N; j++)
			Count[i][j] += Count[i+1][j+1];
		for(int j=1; j<=N; j++)
			Count[i][j] += Count[i+1][j-1];
	}

	if((1ll << N) - Count[0][0] < K) {
		printf("-1\n");
		return 0;
	}

	long long nowK = K;
	int nowH = 0;
	for(int i=0; i<N; i++) {
		if(NoNoCount(i+1, nowH + 1) >= nowK) {
			printf("(");
			nowH += 1;
		}else{
			printf(")");
			nowK -= NoNoCount(i+1, nowH + 1);
			nowH -= 1;
			if(nowH >= 0) continue;
			
			for(int j=i+1; j<N; j++) {
				if( (1ll << (N-j-1) ) >= nowK ) {
					printf("(");
				}else{
					nowK -= (1ll << (N-j-1));
					printf(")");
				}
			}
			break;
			
		}
	}
	printf("\n");

	return 0;
}




