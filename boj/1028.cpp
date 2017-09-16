//
//  main.cpp
//  1028
//
//  Created by KJBS2 on 03/01/2016.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 777;
const int INF = 0x7fffffff;

int N, M;
int Diamond[MAX_N][MAX_N];
int DataSide[4][MAX_N][MAX_N];
int Data[2][MAX_N][MAX_N];
int ChangeX[4] = {1, 1, -1, -1};
int ChangeY[4] = {1, -1, 1, -1};
int Answer = 0;

void MakeDataWithInput() {
		scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++)
		scanf("%1d", &Diamond[i][j]);

	for(int k = 0; k < 2; k++) for(int i = N; i >= 1; i--) for(int j = 1; j <= M; j++)
		if(Diamond[i][j] == 1) DataSide[k][i][j] = DataSide[k][i+ChangeX[k]][j+ChangeY[k]] + 1;
	for(int k = 2; k < 4; k++) for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++)
		if(Diamond[i][j] == 1) DataSide[k][i][j] = DataSide[k][i+ChangeX[k]][j+ChangeY[k]] + 1;

	for(int k = 0; k < 2; k++) for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++)
		Data[k][i][j] = min(DataSide[k*2][i][j], DataSide[k*2+1][i][j]);
}

int MaxIndex;
int IndexTree[2][MAX_N*3];

void TreeUpdate(int isOdd, int index, int value) {
	IndexTree[isOdd][index] = value;
	while(index /= 2)
		IndexTree[isOdd][index] = max(IndexTree[isOdd][index * 2], IndexTree[isOdd][index * 2 + 1]);
}

int GetLengthWithValue(int isOdd, int indexL, int indexR, int value) {
	int findNode = -1, baseL = indexL;
	while(indexL <= indexR) {
		if(IndexTree[isOdd][indexR] >= value) {
			findNode = indexR;
			break;
		}
		indexL = (indexL + 1) / 2;
		indexR = (indexR - 1) / 2;
	}
	if(findNode == -1) return -1;

	while(findNode < MaxIndex) {
		if(IndexTree[isOdd][findNode * 2 + 1] >= value)
			findNode = findNode * 2 + 1;
		else
			findNode = findNode * 2;
	}
	return findNode - baseL + 1;
}

int main() {
	MakeDataWithInput();

	for(MaxIndex = 1; MaxIndex < N; MaxIndex <<= 1);
	for(int isOdd = 0; isOdd < 2; isOdd++)
		for(int index = MaxIndex; index < MaxIndex*2; index++)
			IndexTree[isOdd][index] = -INF;

	int Answer = 0;
	for(int j = 1; j <= M; j++) {
		for(int i = 1; i <= N; i++)
			TreeUpdate(i%2, MaxIndex + (i-1)/2, Data[1][i][j] - (i-1)/2);
		for(int i = 1; i <= N; i++) {
			int rightR = (i%2 == 0) ? min((i-1)/2 + Data[0][i][j] - 1, (N-2)/2) : min((i-1)/2 + Data[0][i][j] - 1, (N-1)/2);
			Answer = max(Answer, GetLengthWithValue(i%2, MaxIndex + (i-1)/2, MaxIndex + rightR, -(i-1)/2) );
		}
	}

	printf("%d\n", Answer);
	return 0;	
}
