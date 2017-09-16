//
//  main.cpp
//  1025
//
//  Created by KJBS2 on 03/01/2016.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <set>

using namespace std;

set<int> Squares;

int N, M;
int Nr[9][9];
int Answer = -1;

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++)
		scanf("%1d", &Nr[i][j]);

	for(int i = 0; i*i < 1000000000; i++)
		Squares.insert(i*i);

	if(N == 1 && M == 1) {
		if(Squares.find(Nr[0][0]) != Squares.end()) printf("%d\n", Nr[0][0]);
		else printf("-1\n");
		return 0;
	}

	for(int i0 = 0; i0 < N; i0++) for(int j0 = 0; j0 < M; j0++)
		for(int i1 = 0; i1 < N; i1++) for(int j1 = 0; j1 < M; j1++) {
			int diffI = i1 - i0, diffJ = j1 - j0;
			if(diffI == 0 && diffJ == 0) continue;
			
			for(int nowI = i0, nowJ = j0, nowNr = 0; ; nowI += diffI, nowJ += diffJ) {
				if(nowI < 0 || nowI >= N || nowJ < 0 || nowJ >= M) break;
				nowNr = nowNr * 10 + Nr[nowI][nowJ];
				if(nowNr > Answer && Squares.find(nowNr) != Squares.end())
					Answer = nowNr;
			}
			
		}

	printf("%d\n", Answer);

	return 0;
}




