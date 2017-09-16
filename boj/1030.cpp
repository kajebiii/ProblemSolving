//
//  main.cpp
//  1030
//
//  Created by KJBS2 on 03/04/2016.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

int S, N, K, R1, R2, C1, C2;
int Answer[51][51];

struct RECT{
	int x1, x2;
	int y1, y2;
};

bool isInBlackArea(int i, int j) {
	if(i < (N-K)/2 || N-i <= (N-K)/2) return false;
	if(j < (N-K)/2 || N-j <= (N-K)/2) return false;
	return true;
}

RECT GetArea(RECT input, RECT condition) {
	RECT result = input;
	result.x1 = max(result.x1, condition.x1);
	result.x2 = min(result.x2, condition.x2);
	result.y1 = max(result.y1, condition.y1);
	result.y2 = min(result.y2, condition.y2);

	if(result.x1 > result.x2 || result.y1 > result.y2) return {-1, -1, -1, -1};
	return result;
}

void GetAnswer(int size, RECT base, RECT find, bool isInBlack) {
	if(isInBlack) {
		for(int i = find.x1; i <= find.x2; i++)
			for(int j = find.y1; j <= find.y2; j++)
				Answer[i - R1][j - C1] = 1;
		return;
	}
	if(size == 1)
		return;

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++) {
			RECT condition = {base.x1 + size/N*i, base.x1 + size/N*(i+1) - 1, base.y1 + size/N*j, base.y1 + size/N*(j+1) - 1};
			RECT nextFind = GetArea(find, condition);
			if(nextFind.x1 == -1) continue;
			if(isInBlackArea(i, j)) 
				GetAnswer(size/N, condition, nextFind, true);
			else
				GetAnswer(size/N, condition, nextFind, false);
		}
}

int main() {
	scanf("%d%d%d%d%d%d%d", &S, &N, &K, &R1, &R2, &C1, &C2);

	int size = []()->int{
		int result = 1;
		for(int i=0; i<S; i++)
			result *= N;
		return result;
	}();

	RECT largeArea = {0, size-1, 0, size-1};
	RECT findArea  = {R1, R2, C1, C2};

	GetAnswer(size, largeArea, findArea, false);

	for(int i = 0; i <= R2 - R1; printf("\n"), i++) for(int j = 0; j <= C2 - C1; printf("%d", Answer[i][j]), j++);
    return 0;
}

