//
//  main.cpp
//  10430
//
//  Created by KJBS2 on 2016. 1. 17..
//  Copyright (c) 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>

int A, B, C;

int main() {
    scanf("%d%d%d", &A, &B, &C);
    printf("%d\n%d\n%d\n%d\n"
           , (A+B)%C, (A%C + B%C) % C
           , (A*B)%C, (A%C * B%C) % C);
}