//
//  main.cpp
//  1035
//
//  Created by KJBS2 on 03/07/2016.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 0x7fffffff;

int ChangeX[4] = {-1, 0, 1, 0};
int ChangeY[4] = {0, -1, 0, 1};

int N = 5, M = 5;
vector<int> DataIndex[6];
vector< pair<int, int> > Point;
vector< pair<int, int> > Data[2100];

void PREPROCESS() {

	char map[9][9];
	for(int i = 1; i <= N; i++) {
		scanf("%s", map[i] + 1);
		for(int j = 1; j <= M; j++)
			if(map[i][j] == '*')
				Point.push_back(make_pair(i, j));
	}

	int maxIndex = -1;
	Data[0].push_back(make_pair(0, 0));
	DataIndex[1].push_back(++maxIndex);
	for(int size = 1; size < Point.size(); size++) {
		for(int index : DataIndex[size]) {
			for(int k = 0; k < 4; k++) {
				for(pair<int, int> last : Data[index]) {		
					bool isOverlap = false;
					pair<int, int> newPoint = make_pair(last.first + ChangeX[k], last.second + ChangeY[k]);
					for(pair<int, int> point : Data[index])
						if(point == newPoint)
							isOverlap = true;
					if(isOverlap == true) continue;

					DataIndex[size + 1].push_back(++maxIndex);
					for(pair<int, int> point : Data[index])
						Data[maxIndex].push_back(point);
					Data[maxIndex].push_back(newPoint);
				}
			}
		}
	}

	return;
}

int getDistance(pair<int, int> X, pair<int, int> Y) {
	return abs(X.first - Y.first) + abs(X.second - Y.second);
}

int main() {
	PREPROCESS();

	int Answer = INF;
	int match[5] = {0, 1, 2, 3, 4};
	for(int index : DataIndex[Point.size()]) {
		for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) {
			bool isInBoundary = true;
			for(pair<int, int> point : Data[index]) {
				if(point.first  + i < 1 || point.first  + i > N) isInBoundary = false;
				if(point.second + j < 1 || point.second + j > M) isInBoundary = false;
			}
			if(isInBoundary == false) continue;

			for(int k = 0; k < Point.size(); k++)
				match[k] = k;

			do{
				int nowAnswer = 0, cnt = 0;
				for(pair<int, int> point : Data[index]) {
					pair<int, int> nowPoint = make_pair(point.first + i, point.second + j);
					nowAnswer += getDistance(nowPoint, Point[match[cnt++]]);
				}
				if(Answer > nowAnswer)
					Answer = nowAnswer;
			}while(next_permutation(match, match + Point.size() ) );
		}
	}

	printf("%d\n", Answer);

	return 0;
}





