//
//  main.cpp
//  10817
//
//  Created by KJBS2 on 2016. 1. 17..
//  Copyright (c) 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);
    
    printf("%d", A + B + C - max(A, max(B, C)) - min(A, min(B, C)));
    return 0;
}