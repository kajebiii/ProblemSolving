//
//  main.cpp
//  1012
//
//  Created by KJBS2 on 2016. 1. 21..
//  Copyright (c) 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>

const int MAX_K = (int)5e3;
const int MAX_N = (int)7e1;

int UnF[MAX_K][2];
int Find(int v) {
    return UnF[v][0] == 0 ? v : UnF[v][0] = Find(UnF[v][0]);
}
void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    
    if(a == b) return;
    
    if(UnF[a][1] < UnF[b][1]) {
        UnF[a][0] = b;
    }else{
        UnF[b][0] = a;
        if(UnF[a][1] == UnF[b][1])
            UnF[a][1]++;
    }
}

int Map[MAX_N][MAX_N];
int P[MAX_K][2];

int N, M, K;
int Cx[4] = {0, 1, 0, -1};
int Cy[4] = {1, 0, -1, 0};

void PROCESS() {
    scanf("%d%d%d", &N, &M, &K);
    for(int i=0; i<=N+1; i++) for(int j=0; j<=M+1; j++)
        Map[i][j] = 0;
    for(int i=1; i<=K; i++)
        UnF[i][0] = 0, UnF[i][1] = 1;

    for(int i=1; i<=K; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        P[i][0] = x;
        P[i][1] = y;
        Map[x][y] = i;
    }
    
    for(int i=1; i<=K; i++) {
        for(int k=0; k<4; k++) {
            int nx = P[i][0] + Cx[k];
            int ny = P[i][1] + Cy[k];
            
            if(Map[nx][ny] == 0) continue;
            
            Union(Map[nx][ny], i);
        }
    }
    
    int result = 0;
    
    for(int i=1; i<=K; i++)
        if(Find(i) == i)
            result++;
    
    printf("%d\n", result);
}

int main() {
    int T;
    scanf("%d", &T);
    
    for(int i=0; i<T; i++)
        PROCESS();
    
    return 0;
}