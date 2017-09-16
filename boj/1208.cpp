//
//  main.cpp
//  1208
//
//  Created by KJBS2 on 2016. 8. 7..
//  Copyright © 2016년 KJBS2. All rights reserved.
//


#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;
int Nr[50];
vector<int> V[2];

vector<int> K;

int main()
{
    scanf("%d%d", &N, &S);
    for(int i=0; i<N; i++)
        scanf("%d", &Nr[i]);
    if(N == 1)
    {
        if(S == Nr[0])
            printf("1");
        else
            printf("0");
        return 0;
    }
    
    for(int o=0; o<(1<<(N/2)); o++)
    {
        int sum = 0;
        for(int i=0; i<N/2; i++)
            if( o & (1 << i) )
                sum += Nr[i];
        V[0].push_back(sum);
    }
    
    for(int o=0; o<(1<<(N - N/2)); o++)
    {
        int sum = 0;
        for(int i=N/2; i<N; i++)
            if( o & (1 << (i - N/2) ) )
                sum += Nr[i];
        V[1].push_back(sum);
    }
    
    for(int j=0; j<2; j++)
        sort(V[j].begin(), V[j].end());
    
    long long result = 0;
    for(int i=0; i<V[0].size(); i++)
    {
        int now = V[0][i];
        int how = (int)(upper_bound(V[1].begin(), V[1].end(), S - now) - V[1].begin())
                - (int)(lower_bound(V[1].begin(), V[1].end(), S - now) - V[1].begin());
        result += 1ll * how;
    }
    if(S == 0)
        result--;
    
    printf("%lld\n", result);
    
    
    return 0;
}











