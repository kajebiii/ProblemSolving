//
//  main.cpp
//  A
//
//  Created by KJBS2 on 2015. 5. 30..
//  Copyright (c) 2015년 KJBS2. All rights reserved.
//

#include <stdio.h>

#define MAX_N 200

int N, M;
char Map[MAX_N][MAX_N];

char CC[4] ={'>', 'v', '<', '^'};
int CX[4] ={0, 1, 0, -1};
int CY[4] ={1, 0, -1, 0};

void Process(int t) {
	scanf("%d%d", &N, &M);

	for(int i=1; i<=N; i++)
		scanf("%s", Map[i]+1);

	int ans = 0;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) {
		if(Map[i][j] == '.') continue;

		bool flag = false;
		bool same = false;
		for(int k=0; k<4; k++) {
			int l = 0;
			bool find = false;
			while(1) {
				l++;
				int ii = i + CX[k] * l;
				int jj = j + CY[k] * l;

				if(ii<=0 || ii>N || jj<=0 || jj>M) break;
				if(Map[ii][jj] != '.') {
					find = true;
					break;
				}
			}
			if(find) flag = find;

			if(find && CC[k] == Map[i][j]) {
				same = true;
				break;
			}
		}
		if(!flag) {
			printf("Case #%d: IMPOSSIBLE\n", t);
			return;
		}
		if(!same) {
			ans++;
		}
	}
	printf("Case #%d: %d\n", t, ans);
	return;
}

int main() {
	int T; scanf("%d", &T);
	for(int t=1; t<=T; t++)
		Process(t);
	return 0;
}
