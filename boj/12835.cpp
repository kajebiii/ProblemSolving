//
//  main.cpp
//  4
//
//  Created by KJBS2 on 6/21/16.
//  Copyright © 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = (5e5) + 1;

int N;
long long L;
long long Result;
int WhereAnt[3];

int AntN;
struct ANT
{
    int road;
    long long where;
    
    const bool operator<(const ANT &other) const
    {
        if(where == other.where) return road < other.road;
        return where < other.where;
    }
}Ant[MAX_N];

int main()
{
    scanf("%d%lld", &N, &L);
    for(int i=0; i<N; i++)
    {
        char a;
        long long where;
        int direc;
        scanf("\n%c%lld%d", &a, &where, &direc);
        if(direc == 1)
        {
            Result += (L - where);
            WhereAnt[a - 'A']++;
            continue;
        }
        Result += (L + where);
        Ant[AntN].road = a - 'A';
        Ant[AntN].where = where;
        AntN++;
    }
    sort(Ant, Ant + AntN);
    Ant[AntN].where = -1;
    
    int start = 0;
    int end = -1;
    for(int i=0; i<AntN; i++)
    {
        if(Ant[i].where != Ant[i+1].where)
        {
            end = i;
            if( (end - start) == 0)
            {
                WhereAnt[ (Ant[i].road + 1)%3]++;
            }
            else
            {
                for(int j=start; j<=end; j++)
                    WhereAnt[Ant[j].road]++;
            }
            start = i+1;
        }
    }
    
    printf("%lld\n", Result);
    for(int i=0; i<3; i++)
        printf("%d ", WhereAnt[i]);
    return 0;
}




