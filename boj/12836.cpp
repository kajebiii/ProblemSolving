//
//  main.cpp
//  2
//
//  Created by KJBS2 on 6/21/16.
//  Copyright © 2016 KJBS2. All rights reserved.
//

#include <stdio.h>

const int MAX_N = (1e6) + 1;

int N, Q, T;
long long IdxT[4*MAX_N];

void Update(int v, int k)
{
    IdxT[v] += 1ll * k;
    while(v/=2)
        IdxT[v] = IdxT[v*2] + IdxT[v*2+1];
    return;
}

long long GetPQ(int p, int q)
{
    long long result = 0;
    while(p <= q)
    {
        if(p%2 == 1) result += IdxT[p++];
        if(q%2 == 0) result += IdxT[q--];
        p/=2;
        q/=2;
    }
    return result;
}

int main()
{
    scanf("%d%d", &N, &Q);
    for(T=1; T<N; T<<=1);
    for(int i=0; i<Q; i++)
    {
        int k, p, q;
        scanf("%d%d%d", &k, &p, &q);
        if(k==1) Update(T+p-1, q);
        if(k==2) printf("%lld\n", GetPQ(T+p-1, T+q-1));
    }
}






