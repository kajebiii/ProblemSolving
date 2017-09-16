//
//  main.cpp
//  10871
//
//  Created by KJBS2 on 2016. 1. 17..
//  Copyright (c) 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>

int N, X;

int main() {
    scanf("%d%d", &N, &X);
    for(int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        if(x < X) printf("%d ", x);
    }
}
