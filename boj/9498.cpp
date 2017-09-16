//
//  main.cpp
//  9498
//
//  Created by KJBS2 on 2016. 1. 17..
//  Copyright (c) 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>

int S;

int main() {
    scanf("%d", &S);
    
    switch (S / 10) {
        case 10:
        case 9:
            printf("A"); break;
        case 8:
            printf("B"); break;
        case 7:
            printf("C"); break;
        case 6:
            printf("D"); break;
        default:
            printf("F"); break;
    }
}