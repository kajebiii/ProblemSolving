//
//  main.cpp
//  10214
//
//  Created by KJBS2 on 5/27/16.
//  Copyright © 2016 KJBS2. All rights reserved.
//

#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; t++)
    {
        int yonsei = 0, korea = 0;
        for(int i = 0; i < 9; i++)
        {
            int y, k;
            scanf("%d%d", &y, &k);
            yonsei += y;
            korea  += k;
        }
        if(yonsei > korea)
            printf("Yonsei\n");
        else if(yonsei < korea)
            printf("Korea\n");
        else
            printf("Draw\n");
        
    }
}