//
//  main.cpp
//  10217
//
//  Created by KJBS2 on 5/27/16.
//  Copyright © 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stdlib.h>

using namespace std;

const int MAX_N = 100;
const int MAX_M = 10000;
const int INF = 0x7fffffff;

int N, M, K;
struct LINE
{
    int v;
    int m;
    int t;
};
vector<LINE> L[MAX_N+1];
int minTime[MAX_M+1][MAX_N+1];

void PROCESS()
{
    scanf("%d%d%d", &N, &M, &K);
    for(int i=0; i<K; i++)
    {
        int start;
        LINE temp;
        scanf("%d%d%d%d", &start, &temp.v, &temp.m, &temp.t);
        L[start].push_back(temp);
    }
    
    for(int m=0; m<=M; m++)
        for(int i=1; i<=N; i++)
            minTime[m][i] = INF;
    minTime[0][1] = 0;
    
    for(int m=0; m<=M; m++)
        for(int i=1; i<=N; i++)
        {
            if(minTime[m][i] == INF) continue;
            int nowTime = minTime[m][i];
            for(auto nowL:L[i])
            {
                if(m + nowL.m > M) continue;
                if(nowTime + nowL.t < minTime[m + nowL.m][nowL.v])
                    minTime[m + nowL.m][nowL.v] = nowTime + nowL.t;
            }
        }

    int result = INF;
    for(int m=0; m<=M; m++)
        result = min(result, minTime[m][N]);
    if(result == INF)
        printf("Poor KCM\n");
    else
        printf("%d\n", result);
    
    for(int i=1; i<=N; i++)
    {
        L[i].clear();
        L[i].shrink_to_fit();
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int i=0; i<T; i++)
        PROCESS();
    return 0;
}






