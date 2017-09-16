//
//  main.cpp
//  1049
//
//  Created by KJBS2 on 2016. 8. 3..
//  Copyright © 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

int N, M;
int Min6 = 1e5, Min1 = 1e5;


int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<M; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        Min6 = min(Min6, x);
        Min1 = min(Min1, y);
    }
    Min6 = min(Min6, Min1 * 6);
    
    printf("%d", min((N/6) * Min6 + (N%6) * Min1, ((N-1)/6 + 1) * Min6) );
    return 0;
}