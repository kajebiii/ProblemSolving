//
//  main.cpp
//  H
//
//  Created by KJBS2 on 2016. 8. 6..
//  Copyright © 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>

int A[10], N;
int Check[10];

bool select(int n)
{
    if(n == 8)
    {
        if( ((A[1] + A[2]) * 10000 + (A[3] + A[4]) * 1000 + (A[5] + A[6]) * 100 + (A[5] + A[5]) * 10 + (A[4] + A[7]) * 1) ==  N  )
        {
            printf("  %d%d%d%d%d\n", A[1], A[3], A[5], A[5], A[4]);
            printf("+ %d%d%d%d%d\n", A[2], A[4], A[6], A[5], A[7]);
            printf("-------\n");
            if(N > 99999)
                printf(" %d", N);
            else
                printf("  %d", N);
            return true;
        }
        return false;
        
    }
    int p = 0;
    if(n == 1 || n == 2)
        p = 1;
    for(int i=p; i<10; i++)
    {
        if(Check[i] == 1) continue;
        A[n] = i;
        Check[i] = 1;
        if(select(n+1)) return true;
        Check[i] = 0;
    }
    return false;
}

int main()
{
    scanf("%d", &N);
    if(select(1))
    {
        
    }
    else
    {
        printf("No Answer\n");
    }
    return 0;
}