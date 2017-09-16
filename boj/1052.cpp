//
//  main.cpp
//  1052
//
//  Created by KJBS2 on 2016. 8. 4..
//  Copyright © 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <deque>

using namespace std;

int N, K;
deque<int> DQ;

int main()
{
    scanf("%d%d", &N, &K);
    int power = 1;
    while(N)
    {
        if( (N%(power*2)) == power)
        {
            DQ.push_front(power);
            N -= power;
        }
        power *= 2;
    }
    
    int result = 0;
    while(DQ.size() > K)
    {
        int now = DQ.back();
        DQ.pop_back();
        
        result += now;
        now *= 2;
        while(!DQ.empty() && DQ.back() == now)
        {
            DQ.pop_back();
            now *= 2;
        }
        DQ.push_back(now);
    }
    
    printf("%d\n", result);
    
    return 0;
}







