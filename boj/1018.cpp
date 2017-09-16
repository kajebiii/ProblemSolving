//
//  main.cpp
//  1018
//
//  Created by KJBS2 on 2/7/16.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 6e1;

int N, M;
char Board[MAX_N][MAX_N];
int sumWhite[2][MAX_N][MAX_N];

int main() {
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
        scanf("%s", Board[i] + 1);
    
    for(int k=0; k<2; k++)
        for(int i=1; i<=N; i++)
            for(int j=1; j<=M; j++) {
                sumWhite[k][i][j] = sumWhite[k][i][j-1] + sumWhite[k][i-1][j] - sumWhite[k][i-1][j-1];
                if((i+j) % 2 == k && Board[i][j] == 'W')
                    sumWhite[k][i][j] += 1;
            }
    
    int result = 0x7fffffff;
    
    for(int i=8; i<=N; i++)
        for(int j=8; j<=M; j++) {
            int result0 = sumWhite[0][i][j] - sumWhite[0][i][j-8] - sumWhite[0][i-8][j] + sumWhite[0][i-8][j-8];
            int result1 = sumWhite[1][i][j] - sumWhite[1][i][j-8] - sumWhite[1][i-8][j] + sumWhite[1][i-8][j-8];
            
            result = min(result, result0 + 32 - result1);
            result = min(result, result1 + 32 - result0);
        }
    
    printf("%d\n", result);
    return 0;
}