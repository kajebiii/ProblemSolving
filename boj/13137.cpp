//
//  main.cpp
//  E
//
//  Created by KJBS2 on 2016. 8. 6..
//  Copyright © 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>

const int MAX_N = 120;

int N;
int P[MAX_N];
int Test[100001];

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", &P[i]);
    
    Test[0] = 0;
    for(int i=1; i<=100000; i++)
        Test[i] = 10000000;
    for(int i=1; i<=100000; i++)
    {
        int findIx = -1, lastJ = -1;
        for(int j=1; j<=N; j++)
        {
            if(i < P[j]) break;
            lastJ = j;
            if(Test[i] >= Test[i - P[j]] + 1)
            {
                Test[i] = Test[i - P[j]] + 1;
                findIx = j;
            }
        }
        
        if(findIx != lastJ)
        {
            printf("No\n");
            return 0;
        }
        
    }
    printf("Yes\n");
    
    
    return 0;
}