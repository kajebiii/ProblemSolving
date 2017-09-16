//
//  main.cpp
//  1038
//
//  Created by KJBS2 on 03/14/2016.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

int Choose[10];
int Decrease[1050];
int N;

int main() {
	scanf("%d", &N);
	if(N > 1022) {
		printf("-1\n");
		return 0;
	}
	if(N == 1022) {
		printf("9876543210\n");
		return 0;
	}

	int cnt = 0;
	for(int k = 1; k <= 10; k++) {
		for(int i = 0; i < 10; i++)
			if(i < 10 - k) 
				Choose[i] = 0;
			else
				Choose[i] = 1;

		do{
			int now = 0;
			for(int i = 0; i < 10; i++) {
				if(Choose[i] == 0) continue;
				now = now * 10 + (9 - i);
			}
			Decrease[cnt++] = now;
		}while(next_permutation(Choose, Choose + 10));
	}
	printf("%d\n", Decrease[N]);

	return 0;
}