//
//  main.cpp
//  1021
//
//  Created by KJBS2 on 2/9/16.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = (int)9e1;

int N, M;
int Nr[MAX_N];

int main() {
    scanf("%d%d", &N, &M);
    for(int i=1; i<=M; i++) {
        scanf("%d", &Nr[i]);
        Nr[i]--;
    }
    
    int result = 0;
    for(int k=1; k<=M; k++) {
        result += min(Nr[k], N-k+1 - Nr[k]);
        
        for(int i=k+1; i<=M; i++)
            Nr[i] = (Nr[i] + N-k+1 - (Nr[k]+1)) % (N-k+1);
    }
    
    printf("%d", result);
    
    return 0;
}