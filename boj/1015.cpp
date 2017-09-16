//
//  main.cpp
//  1015
//
//  Created by KJBS2 on 2/7/16.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = (int)1e2;

struct NODE{
    int value;
    int index;
};

bool operator<(NODE first, NODE second) {
    if(first.value == second.value)
        return first.index < second.index;
    return first.value < second.value;
}

int N;

int main() {
    scanf("%d", &N);
    
    NODE Number[MAX_N];
    
    for(int i=0; i<N; i++) {
        scanf("%d", &Number[i].value);
        Number[i].index = i;
    }
    sort(Number, Number + N);
    
    int Result[MAX_N];
    for(int i=0; i<N; i++)
        Result[Number[i].index] = i;
    
    for(int i=0; i<N; i++)
        printf("%d ", Result[i]);
    
    return 0;
}