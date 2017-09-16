//
//  main.cpp
//
//  Created by KJBS2 on 5/29/16.
//  Copyright © 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int INF = 0x7fffffff;

int N;
int Nr[6];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<6; i++)
        scanf("%d", &Nr[i]);
    
    if(N == 1)
    {
        int maxNr = 0;
        int sum = 0;
        for(int i=0; i<6; i++)
        {
            maxNr = max(maxNr, Nr[i]);
            sum += Nr[i];
        }
        printf("%d\n", sum - maxNr);
        return 0;
    }
    
    int oneMin = INF;
    for(int i=0; i<6; i++)
        oneMin = min(oneMin, Nr[i]);
    
    int twoMin = INF;
    int side1[4] = {1, 1, 4, 4};
    int side2[4] = {2, 3, 2, 3};
    for(int i=0; i<4; i++)
        twoMin = min(twoMin, Nr[side1[i]] + Nr[side2[i]]);
    for(int i=1; i<=4; i++)
    {
        twoMin = min(twoMin, Nr[i] + Nr[0]);
        twoMin = min(twoMin, Nr[i] + Nr[5]);
    }
    
    int threeMin = INF;
    for(int i=0; i<4; i++)
    {
        threeMin = min(threeMin, Nr[0] + Nr[side1[i]] + Nr[side2[i]]);
        threeMin = min(threeMin, Nr[5] + Nr[side1[i]] + Nr[side2[i]]);
    }
    
    long long oneSum = 1ll * oneMin * ( 4*(N-2) + 1ll * 5*(N-2)*(N-2) );
    long long twoSum = 1ll * twoMin * ( 8*(N-2) + 4);
    long long threeSum = 1ll * threeMin * 4;
    printf("%lld", oneSum + twoSum + threeSum);
    
    return 0;
}









