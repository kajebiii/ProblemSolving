//
//  main.cpp
//  1007
//
//  Created by KJBS2 on 2016. 1. 19..
//  Copyright (c) 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

const int MAX_N = 20;

int N;
int Nr[MAX_N][2];
int Select[MAX_N];

void PROCESS() {
    scanf("%d", &N);
    
    for(int i=0; i<N; i++)
        scanf("%d%d", &Nr[i][0], &Nr[i][1]);
    
    for(int i=0; i<N; i++)
        if(i < N / 2)
            Select[i] = 0;
        else
            Select[i] = 1;
    
    double result = 50000000;
    
    int Sum[2] = {0, 0};
    do{
        Sum[0] = Sum[1] = 0;
        for(int i=0; i<N; i++) {
            if(Select[i] == 0) {
                Sum[0] -= Nr[i][0];
                Sum[1] -= Nr[i][1];
            }else{
                Sum[0] += Nr[i][0];
                Sum[1] += Nr[i][1];
            }
        }
        double now = sqrt( (double)1 * Sum[0] * Sum[0] + (double)1 * Sum[1] * Sum[1] );
        
        if(result > now)
            result = now;
    }while(next_permutation(Select, Select+N));
    
    printf("%.6lf\n", result);
}

int main() {
    int T;
    scanf("%d", &T);
    
    for(int i=0; i<T; i++)
        PROCESS();
    
    return 0;
}
