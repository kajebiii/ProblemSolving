//
//  main.cpp
//  1033
//
//  Created by KJBS2 on 03/07/2016.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>

const int MAX_N = 20;

int N;
int RatioData[MAX_N][MAX_N][2];
bool Check[MAX_N];
int Ratio[MAX_N][2];

void getRatio(int now, int ratioX, int ratioY) {
	Check[now] = true;
	Ratio[now][0] = ratioX;
	Ratio[now][1] = ratioY;

	for(int next = 0; next < N; next++) {
		if(Check[next] == true) continue;
		if(RatioData[now][next][0] == 0) continue;
		getRatio(next, ratioX * RatioData[now][next][0], ratioY * RatioData[now][next][1]);
	}
}

int getGCD(int a, int b) {
	if(b == 0) return a;
	return getGCD(b, a % b);
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i < N; i++) {
		int a, b, x, y;
		scanf("%d%d%d%d", &a, &b, &x, &y);
		RatioData[a][b][0] = y;
		RatioData[a][b][1] = x;
		RatioData[b][a][0] = x;
		RatioData[b][a][1] = y;
	}
//	a -> b : [0] / [1] 배가 된다.

	getRatio(0, 1, 1);

	int commonDenominator = 1;
	for(int i = 0; i < N; i++) {
		int nowGCD = getGCD(Ratio[i][0], Ratio[i][1]);
		Ratio[i][0] /= nowGCD;
		Ratio[i][1] /= nowGCD;
	}
	for(int i = 0; i < N; i++)
		commonDenominator = commonDenominator / getGCD(commonDenominator, Ratio[i][1]) * Ratio[i][1];

	for(int i = 0; i < N; i++)
		printf("%d ", commonDenominator / Ratio[i][1] * Ratio[i][0]);

	return 0;
}