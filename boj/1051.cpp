//
//  main.cpp
//  1051
//
//  Created by KJBS2 on 2016. 8. 4..
//  Copyright © 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>

int N, M;
int Nr[999][999];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
        {
            scanf("%1d", &Nr[i][j]);
            Nr[i][j]++;
        }
    
    for(int k=100; k>=0; k--)
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                if(Nr[i][j] == Nr[i][j+k] && Nr[i][j] == Nr[i+k][j] && Nr[i][j] == Nr[i+k][j+k])
                {
                    printf("%d\n", (k+1)*(k+1) );
                    return 0;
                }
    return 0;
}