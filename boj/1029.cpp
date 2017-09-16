//
//  main.cpp
//  1029
//
//  Created by KJBS2 on 03/04/2016.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 15;
const int INF = 0x7fffffff;

int N;
int Price[MAX_N][MAX_N];
int SetBit[MAX_N];
int Dy[MAX_N][1 << MAX_N];

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
		scanf("%1d", &Price[i][j]);

	int Answer = 1;

	for(int i = 0; i < N; i++)
		for(int j = 0; j < 1 << N; j++)
			Dy[i][j] = INF;

	Dy[0][1 << 0] = 0;
	for(int k = 1; k < N; k++) {
		for(int i = 0; i < N; i++)
			if(i >= N - k) SetBit[i] = 1;
			else SetBit[i] = 0;

		do{
			int nowBit = 0;
			for(int i = 0; i < N; i++)
				if(SetBit[i] == 1)
					nowBit += 1 << i;
			for(int i = 0; i < N; i++)
				if(SetBit[i] == 1 && Dy[i][nowBit] != INF)
					for(int next = 0; next < N; next++)
						if(SetBit[next] == 0 && Dy[i][nowBit] <= Price[i][next]) {
							Dy[next][nowBit + (1<<next)] = min(Dy[next][nowBit + (1<<next)], Price[i][next]);
							Answer = k+1;
						}
		}while(next_permutation(SetBit, SetBit + N));
	}

	printf("%d\n", Answer);

	return 0;
}






