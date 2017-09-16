//
//  main.cpp
//  1011
//
//  Created by KJBS2 on 2016. 1. 21..
//  Copyright (c) 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>

int X, Y;

void PROCESS() {
    scanf("%d%d", &X, &Y);
    
    long long maxi = 0;
    
    for(int i=2; ; i++) {
        maxi += 1ll * (i / 2);

        if( Y - X <= maxi ) {
            printf("%d\n", i-1);
            return;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    
    for(int i=0; i<T; i++)
        PROCESS();
    
    return 0;
}