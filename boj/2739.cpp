//
//  main.cpp
//  2739
//
//  Created by KJBS2 on 2016. 1. 17..
//  Copyright (c) 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>

int N;

int main() {
    scanf("%d", &N);
    for(int i=1; i<=9; i++)
        printf("%d * %d = %d\n", N, i, N*i);
}