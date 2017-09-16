//
//  main.cpp
//  2440
//
//  Created by KJBS2 on 2016. 1. 17..
//  Copyright (c) 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>

int N;

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++, printf("\n")) 
        for(int j=N; j>=i; j--) printf("*");
}