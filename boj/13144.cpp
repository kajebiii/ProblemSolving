//
//  main.cpp
//  L
//
//  Created by KJBS2 on 2016. 8. 6..
//  Copyright © 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <set>

using namespace std;

const int MAX_N  = 1e5 + 10;

int N;
int A[MAX_N];
set<int> S;

int main()
{
    scanf("%d", &N);
    
    A[0] = -1;
    S.insert(-1);
    
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &A[i]);
    }
    
    int r = 0, f = 0;
    long long result = 0;
    
    while( (r + 1) <= N)
    {
        S.erase(A[r]);
        r++;
        while( (f + 1) <= N && S.find(A[f+1]) == S.end() )
        {
            S.insert(A[f+1]);
            f++;
        }
        result += 1ll *(f - r + 1);
    }
    
    printf("%lld\n", result);
    
    return 0;
}