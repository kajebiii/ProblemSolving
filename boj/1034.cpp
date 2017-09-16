//
//  main.cpp
//  1034
//
//  Created by KJBS2 on 03/07/2016.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>

const int MAX_N = 55;

int N, M, K;
int Light[MAX_N][MAX_N];
int XOR[MAX_N];

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			scanf("%1d", &Light[i][j]);
	scanf("%d", &K);

	int Answer = 0;

	for(int column = 0; column < N; column++) {
		int changeRow = 0;
		for(int j = 0; j < M; j++) {
			XOR[j] = !Light[column][j];
			changeRow += XOR[j];
		}

		if(changeRow > K || (K - changeRow) % 2 == 1) continue;

		int nowCnt = 0;
		for(int i = 0; i < N; i++) {
			bool isOn = true;
			for(int j = 0; j < M; j++)
				if((Light[i][j] ^ XOR[j]) == 0)
					isOn = false;
			if(isOn) nowCnt++;
		}

		if(Answer < nowCnt)
			Answer = nowCnt;
	}

	printf("%d", Answer);

	return 0;
}