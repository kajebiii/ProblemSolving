//
//  main.cpp
//  1002
//
//  Created by KJBS2 on 2016. 1. 16..
//  Copyright (c) 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>

int N;

struct POINT{
    int x;
    int y;
    
    bool operator==(POINT P) {
        return this->x == P.x && this->y == P.y;
    }
}P[2];

int R[2];

int Dis2(POINT P, POINT Q) {
    return (P.x - Q.x) * (P.x - Q.x) + (P.y - Q.y) * (P.y - Q.y);
}

int main() {
    int T;
    scanf("%d", &T);
    
    for(int i=0; i<T; i++) {
        for(int j=0; j<2; j++)
            scanf("%d%d%d", &P[j].x, &P[j].y, &R[j]);
        
        int maxr = (R[0] + R[1]) * (R[0] + R[1]);
        int minr = (R[0] - R[1]) * (R[0] - R[1]);
        int dis2 = Dis2(P[0], P[1]);
        
        if(P[0] == P[1] && R[0] == R[1])
            printf("-1\n");
        else if(dis2 > maxr || dis2 < minr)
            printf("0\n");
        else if(dis2 < maxr && dis2 > minr)
            printf("2\n");
        else
            printf("1\n");
    }
    
    return 0;
}