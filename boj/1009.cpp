//
//  main.cpp
//  1009
//
//  Created by KJBS2 on 2016. 1. 19..
//  Copyright (c) 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>

int A, B;
int Power5[4] = {1, 2, 4, 3};
int Change[10] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void PROCESS() {
    scanf("%d%d", &A, &B);
    
    int Mod2 = A % 2;
    int Mod5 = A % 5;
    
    if(Mod5 == 1) B *= 4;
    if(Mod5 == 3) B *= 3;
    if(Mod5 == 4) B *= 2;
    
    Mod5 = Mod5 == 0 ? 0 : Power5[B % 4];
    
    if(Mod5 % 2 == Mod2) printf("%d\n", Change[Mod5]);
    else printf("%d\n", Change[Mod5 + 5]);
}

int main() {
    int T;
    scanf("%d", &T);
    
    for(int i=0; i<T; i++)
        PROCESS();
    
    return 0;
}