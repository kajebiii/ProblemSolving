//
//  main.cpp
//
//  Created by KJBS2 on 6/1/16.
//  Copyright © 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <set>
#include <map>

using namespace std;

const int MAX_N = 40;
const int Inf = 0x7fffffff;
const long long INF = 1ll * Inf * Inf;


int N;
long long Nr[MAX_N];

struct NODE
{
    long long sum;
    long long cnt;
    NODE()
    {
        sum = 0;
        cnt = 0;
    }
    NODE(long long a, long long b)
    {
        sum = a;
        cnt = b;
    }
    const bool operator<(const NODE& other) const
    {
        if(sum == other.sum)
            return cnt < other.cnt;
        return sum < other.sum;
    }
};

set<NODE> S[MAX_N];
map<long long, long long> MinCnt[MAX_N];

long long Sum;

NODE Ans = NODE(INF, 0);

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%lld", &Nr[N-1-i]);
    }
    for(int i=0; i<N; i++)
    {
        long long x;
        scanf("%lld", &x);
        Sum += Nr[N-1-i];
        Nr[N-1-i] += x;
    }
    
    for(long long cnt=0; cnt < (1ll << (N/2)); cnt++)
    {
        int nr = 0;
        NODE temp = NODE();
        for(int i=0; i<N/2; i++)
            if(cnt & (1ll << i))
            {
                temp.sum += Nr[i];
                nr++;
            }
        temp.cnt = cnt;
        S[nr].insert(temp);
        
        if(MinCnt[nr].find(temp.sum) == MinCnt[nr].end())
            MinCnt[nr][temp.sum] = temp.cnt;
        else
            if(MinCnt[nr][temp.sum] > temp.cnt)
                MinCnt[nr][temp.sum] = temp.cnt;
    }

    for(int i=0; i<=N/2; i++)
    {
        S[i].insert( NODE(+INF, 0));
        S[i].insert( NODE(-INF, 0));
    }
    
    
    for(long long cnt=0; cnt < (1ll << (N/2)); cnt++)
    {
        int nr = 0;
        long long nowSum = 0;
        for(int i=0; i<N/2; i++)
            if(cnt & (1ll << i))
            {
                nowSum += Nr[i + N/2];
                nr++;
            }
        set<NODE>::iterator it = S[N/2-nr].lower_bound( NODE(Sum - nowSum, 0) );
        
        if(it -> sum != INF && it -> sum != -INF)
        {
            long long dif = llabs(nowSum + it -> sum - Sum);
            long long ct = MinCnt[N/2-nr][it->sum] + ( cnt << (N/2) );
            if( (Ans.sum == dif && Ans.cnt > ct) || Ans.sum > dif)
                Ans = NODE(dif, ct);
        }
        it--;
        if(it -> sum != INF && it -> sum != -INF)
        {
            long long dif = llabs(nowSum + it -> sum - Sum);
            long long ct = MinCnt[N/2-nr][it->sum] + ( cnt << (N/2) );
            if( (Ans.sum == dif && Ans.cnt > ct) || Ans.sum > dif)
                Ans = NODE(dif, ct);
        }
        
    }
    for(int i=N-1; i>=0; i--)
        if(Ans.cnt & (1ll << i))
            printf("2 ");
        else
            printf("1 ");
    
    return 0;
}







