//
//  main.cpp
//  1039_NK
//
//  Created by KJBS2 on 03/21/2016.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1000000;
const int MAX_K = 11;

int N, K;
bool isCan[MAX_K][MAX_N + 1];

int getLength(int n) {
	int result = 0;
	while(n > 0) result++, n /= 10;
	return result;
}
int getIndex(int n, int index) {
	for(int i = 1; i < index; i++) 
		n /= 10;
	return n % 10;
}
int changeIndex(int n, int i, int j) {
	int changeN = n;
	int powerI = 1, powerJ = 1;
	for(int k = 1; k < i; k++) powerI *= 10;
	for(int k = 1; k < j; k++) powerJ *= 10;
	changeN -= getIndex(n, i) * powerI;
	changeN -= getIndex(n, j) * powerJ;
	changeN += getIndex(n, i) * powerJ;
	changeN += getIndex(n, j) * powerI;
	return changeN;
}

int main() {
	scanf("%d%d", &N, &K);

	isCan[0][N] = true;

	for(int k = 1; k <= K; k++)
		for(int n = 1; n <= MAX_N; n++) {
			if(isCan[k - 1][n] == false) continue;
			int nowL = getLength(n);
			for(int i = 1; i <= nowL; i++)
				for(int j = i+1; j <= nowL; j++) {
					if(j == nowL && getIndex(n, i) == 0) continue;
					isCan[k][changeIndex(n, i, j)] = true;
				}
		}

	bool flag = false;
	for(int n = MAX_N; n >= 1; n--)
		if(isCan[K][n] == true) {
			printf("%d\n", n);
			flag = true;
			break;
		}
	if(flag == false) printf("-1\n");

	return 0;
}



