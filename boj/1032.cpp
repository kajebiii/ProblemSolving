//
//  main.cpp
//  1032
//
//  Created by KJBS2 on 03/07/2016.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <string.h>

const int MAX_N = 55;
const int MAX_L = 55;

int N;
char FileName[MAX_N][MAX_L];

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%s", FileName[i]);

	int length = strlen(FileName[0]);
	for(int j = 0; j < length; j++) {
		bool isQuestion = false;
		for(int i = 1; i < N; i++) {
			if(FileName[i][j] != FileName[0][j]) {
				isQuestion = true;
				break;
			}
		}
		if(isQuestion) printf("?");
		else printf("%c", FileName[0][j]);
	}

	return 0;
}
