//
//  main.cpp
//  D
//
//  Created by KJBS2 on 2016. 8. 6..
//  Copyright © 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>

int R, C, N;

int main()
{
    scanf("%d%d%d", &R, &C, &N);
    
    printf("%lld\n", 1ll * ((R-1)/N + 1) * ( (C-1)/N + 1));
    
    return 0;
}