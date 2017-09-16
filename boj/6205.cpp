//
//  main.cpp
//  6205
//
//  Created by KJBS2 on 2016. 8. 7..
//  Copyright © 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 1e2 + 3;
const int MAX_V = 150;
const int MAX_T = 1e4;
const int MAX_M = MAX_T + MAX_V * MAX_V;
const int INF = 0x7fffffff;

int N, T;

int GCD(int a, int b)
{
    if(a == 0) return b;
    return GCD(b%a, a);
}

struct COIN
{
    int v;
    int c;
}Coin[MAX_N];

int  Pay[2][MAX_M];
int Back[MAX_M];

priority_queue< pair<int, int> > Q;

int main()
{
    scanf("%d%d", &N, &T);
    
    int gcd = 0;
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &Coin[i].v);
        gcd = GCD(gcd, Coin[i].v);
    }
    int maxSum = 0;
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &Coin[i].c);
        maxSum += Coin[i].v * Coin[i].c;
    }

    if( (T % gcd) != 0 || maxSum < T)
    {
        printf("-1\n");
        return 0;
    }

    for(int i=0; i<MAX_M; i++)
        Back[i] = INF;
    Back[0] = 0;
    for(int c=1; c<=N; c++)
        for(int i=Coin[c].v; i<MAX_M; i++)
            if(Back[i - Coin[c].v] != INF)
                Back[i] = min(Back[i], Back[i - Coin[c].v] + 1);
//    for(int i=0; i<100; i++)
//        printf("%d : %d\n", i, Back[i]);
    
    for(int i = 0; i < MAX_M; i++)
        Pay[0][i] = INF;
    Pay[0][0] = 0;

    for(int cc=1; cc<=N; cc++)
    {
        int c = cc%2;
        for(int i = 0; i < MAX_M; i++)
            Pay[c][i] = INF;
        for(int start = 0; start < Coin[cc].v; start++)
        {
            while(!Q.empty()) Q.pop();
            for(int i = start, cnt = 0; i < MAX_M; i += Coin[cc].v, cnt++)
            {
                Q.push(make_pair(-Pay[1-c][i] + cnt, cnt));
                int cost = -1, inx = -1;
                while(!Q.empty())
                {
                    inx  = +Q.top().second;
                    cost = -(Q.top().first - inx);
                    if(cnt - inx > Coin[cc].c) {
                        inx = -1;
                        Q.pop();
                        continue;
                    }else break;
                }
//                printf("%d %d : cost %d inx %d\n", cc, i, cost, inx);
                if(inx != -1)
                    if(cost != INF)
                    {
                        Pay[c][i] = cost + (cnt - inx);
//                        printf("%d %d : %d\n", cc, i, Pay[c][i]);
                    }
            }
        }
        
    }
    
    int result = INF;
    for(int i=T; i<MAX_M; i++)
        if(Pay[N%2][i] != INF && Back[i-T] != INF)
        {
            result = min(result, Pay[N%2][i] + Back[i-T]);
//            printf("%d : %d / %d\n", i, Pay[N%2][i], Back[i-T]);
        }
    if(result != INF)
        printf("%d\n", result);
    else
        printf("-1\n");
    return 0;
}

/*
2 1973
109 113
109 113
*/










