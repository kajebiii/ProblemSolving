//
//  main.cpp
//  A
//
//  Created by KJBS2 on 2016. 8. 6..
//  Copyright © 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>

const int MAX_N = 999;

int N;
int M;

int A[MAX_N][2];
int C[MAX_N];

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d%d", &A[i][0], &A[i][1]);
    
    scanf("%d", &M);
    C[0] = 1;
    for(int i=1; i<=M; i++)
    {
        int x;
        scanf("%d", &x);
        C[x] = 1;
    }
    
    int cnt = 0;
    for(int i=1; i<=N; i++)
    {
        if(C[A[i][0]] == 0 && C[A[i][1]] == 0 && C[i] == 0)
            cnt++;
    }
    
    printf("%d\n", cnt);
        
    
    return 0;
}


