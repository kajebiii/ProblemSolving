//
//  main.cpp
//  1006
//
//  Created by KJBS2 on 2016. 1. 19..
//  Copyright (c) 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>

const int MAX_N = (int)1e4 + 30;
const int INF = MAX_N * 10;

int N, W;
int Dy[2][2][MAX_N][2][2];
int Nr[MAX_N][2];

int GetDy(int _0, int _1, int k, int _2, int _3) {
    if(k == N) {
        if(_0 == _2 && _1 == _3) return 0;
        return INF;
    }
    
    if(Dy[_0][_1][k][_2][_3] != INF)
        return Dy[_0][_1][k][_2][_3];
    
    int result = INF;
    
    for(int i=0; i<3; i++) for(int j=0; j<3; j++) {
        int nextk = k+1;
        int next_2 = -1;
        int next_3 = -1;
        int cnt = 0;
        
        if(_2 == 0 && i == 0) continue;
        if(_3 == 0 && j == 0) continue;
        if(_2 == 1 && i >  0) continue;
        if(_3 == 1 && j >  0) continue;
        if(Nr[k][0] + Nr[k+1][0] > W && i == 2) continue;
        if(Nr[k][1] + Nr[k+1][1] > W && j == 2) continue;
        
        if(i == 0)
            next_2 = 0;
        if(j == 0)
            next_3 = 0;
        if(i == 1)
            next_2 = 0, cnt++;
        if(j == 1)
            next_3 = 0, cnt++;
        if(i == 2)
            next_2 = 1, cnt++;
        if(j == 2)
            next_3 = 1, cnt++;
        
        int next = GetDy(_0, _1, nextk, next_2, next_3) + cnt;
        
        if(result > next)
            result = next;
    }
    
    if(_2 == 0 && _3 == 0 && Nr[k][0] + Nr[k][1] <= W) {
        int next = GetDy(_0, _1, k+1, 0, 0) + 1;
        
        if(result > next)
            result = next;
    }
    
    Dy[_0][_1][k][_2][_3] = result;
    
    return Dy[_0][_1][k][_2][_3];
}

void PROCESS() {
    scanf("%d%d", &N, &W);
    for(int j=0; j<2; j++)
        for(int i=0; i<N; i++)
            scanf("%d", &Nr[i][j]);
    Nr[N][0] = Nr[0][0];
    Nr[N][1] = Nr[0][1];
    
    for(int _0 = 0; _0 < 2; _0++) for(int _1 = 0; _1 < 2; _1++)
        for(int i=0; i<=N; i++)
            for(int _2 = 0; _2 < 2; _2++) for(int _3 = 0; _3 < 2; _3++)
                Dy[_0][_1][i][_2][_3] = INF;
    
    int result = INF;
    
    for(int _0 = 0; _0 < 2; _0++) for(int _1 = 0; _1 < 2; _1++) {
        if(_0 == 1 && Nr[N-1][0] + Nr[N][0] > W) continue;
        if(_1 == 1 && Nr[N-1][1] + Nr[N][1] > W) continue;
        
        if(result > GetDy(_0, _1, 0, _0, _1) )
            result = GetDy(_0, _1, 0, _0, _1);
    }
    
    printf("%d\n", result);
}

int main() {
    int T;
    scanf("%d", &T);
    
    for(int i=0; i<T; i++)
        PROCESS();

    return 0;
}