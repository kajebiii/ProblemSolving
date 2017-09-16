//
//  main.cpp
//  1013
//
//  Created by KJBS2 on 2016. 1. 21..
//  Copyright (c) 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <string.h>

const int MAX_N = (int)5e2;

char Signal[MAX_N];
int N;

int Automata[11][2] =
{{1, 4}, {10, 2}, {1, 4}, {99, 99}, {5, 10},
 {6, 10}, {6, 7}, {1, 8}, {9, 8}, {6, 2},
 {10, 10}};

void PROCESS() {
    scanf("%s", Signal);
    N = (int)strlen(Signal);
    
    int now = 0;
    
    for(int i=0; i<N; i++)
        now = Automata[now][Signal[i] - '0'];
    
    if(now == 0 || now == 2 || now == 7 || now == 8)
        printf("YES\n");
    else
        printf("NO\n");
}

int main() {
    int T;
    scanf("%d", &T);
    
    for(int i=0; i<T; i++)
        PROCESS();
    
    return 0;
}