//
//  main.cpp
//  1010
//
//  Created by KJBS2 on 2016. 1. 19..
//  Copyright (c) 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>

const int MOD = (int)1e9 + 7;

int A, B;

int Power(int v, int k) {
    int result = 1;
    int powerv = v;
    
    while(k) {
        if(k%2) result = 1ll * result * powerv % MOD;
        powerv = 1ll * powerv * powerv % MOD;
        
        k /= 2;
    }
    return result;
}

void PROCESS() {
    scanf("%d%d", &A, &B);
    
    int result = 1;
    
    for(int i=1; i<=B; i++)
        result = 1ll * result * i % MOD;
    
    for(int i=1; i<=A; i++)
        result = 1ll * result * Power(i, MOD-2) % MOD;
    
    for(int i=1; i<=B-A; i++)
        result = 1ll * result * Power(i, MOD-2) % MOD;
    
    printf("%d\n", result);
}

int main() {
    int T;
    scanf("%d", &T);
    
    for(int i=0; i<T; i++)
        PROCESS();
    
    return 0;
}