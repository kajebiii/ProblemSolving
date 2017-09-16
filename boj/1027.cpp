//
//  main.cpp
//  1027
//
//  Created by KJBS2 on 03/01/2016.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int MAX_N = 99;

int N;
int Nr[MAX_N];
int AnswerCnt = 0;

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", &Nr[i]);

	for(int k=0; k<N; k++) {
		int dx = -1, dy = -1;
		int nowCnt = 0;
		for(int i=k-1; i>=0; i--) {
			if(1ll * Nr[k]*dx + 1ll * abs(k - i) * dy < 1ll * dx * Nr[i] || i == k-1) {
				dx = abs(k - i);
				dy = Nr[i] - Nr[k];
				nowCnt++;
			}
		}
		for(int i=k+1; i<N; i++) {
			if(1ll * Nr[k]*dx + 1ll * abs(k - i) * dy < 1ll * dx * Nr[i] || i == k+1) {
				dx = abs(k - i);
				dy = Nr[i] - Nr[k];
				nowCnt++;
			}
		}
		AnswerCnt = max(AnswerCnt, nowCnt);
	}

	printf("%d\n", AnswerCnt);

    return 0;
}




