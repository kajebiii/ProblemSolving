//
//  main.cpp
//  10874
//
//  Created by KJBS2 on 2016. 8. 7..
//  Copyright © 2016년 KJBS2. All rights reserved.
//


#include <stdio.h>

int N;

int main()
{
    scanf("%d", &N);
    
    for(int k=1; k<=N; k++)
    {
        bool flag = true;
        for(int i=0; i<=9; i++)
        {
            int x;
            scanf("%d", &x);
            x--;
            if(x != (i%5))
                flag = false;
        }
        
        if(flag)
            printf("%d\n", k);
    }
    return 0;
}









