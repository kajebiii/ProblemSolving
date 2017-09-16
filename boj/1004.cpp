//
//  main.cpp
//  1004
//
//  Created by KJBS2 on 2016. 1. 17..
//  Copyright (c) 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>

struct POINT{
    int x;
    int y;
}P[2];

int N;
int InCirCle(POINT P, int x, int y, int r) {
    int X = (P.x - x) * (P.x - x);
    int Y = (P.y - y) * (P.y - y);
    return (X + Y - r * r) > 0 ? 1 : -1;
}

void PROCESS() {
    scanf("%d%d%d%d", &P[0].x, &P[0].y, &P[1].x, &P[1].y);
    scanf("%d", &N);
    
    int result = 0;
    for(int i=0; i<N; i++) {
        int x, y, r;
        scanf("%d%d%d", &x, &y, &r);
        if(InCirCle(P[0], x, y, r) * InCirCle(P[1], x, y, r) == -1)
            result ++;
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
