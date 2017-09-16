//
//  main.cpp
//  1005
//
//  Created by KJBS2 on 2016. 1. 17..
//  Copyright (c) 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = (int)1e3 + 30;

int N, M;
int Time[MAX_N];
vector<int> V[MAX_N];
int Dy[MAX_N];

int GetTime(int n) {
    if(Dy[n] != -1) return Dy[n];
    
    int result = 0;
    
    for(int i=0; i<V[n].size(); i++) {
        int p = V[n][i];
        result = max(result, GetTime(p));
    }
    
    Dy[n] = result + Time[n];
    
    return Dy[n];
}

void PROCESS() {
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
        scanf("%d", &Time[i]);
    for(int i=0; i<M; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        V[y].push_back(x);
    }
    
    for(int i=1; i<=N; i++)
        Dy[i] = -1;
    
    int Last;
    scanf("%d", &Last);
    
    printf("%d\n", GetTime(Last));
    
    for(int i=1; i<=N; i++) {
        vector<int> newV;
        V[i].swap(newV);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    
    for(int i=0; i<T; i++)
        PROCESS();

    return 0;
}