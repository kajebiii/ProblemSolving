//
//  main.cpp
//  I
//
//  Created by KJBS2 on 2016. 8. 6..
//  Copyright © 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 222;
const int MAX_M = 22222;

int N, M;

struct Line
{
    int x[2];
    int c;
    int t[2];
}L[MAX_M];

vector<int> V[MAX_N];
priority_queue< pair<int, int> > Q;
int Check[MAX_N];

int Fire(int k)
{
    while(!Q.empty()) Q.pop();
    for(int i=1; i<=N; i++)
        Check[i] = 0;
    Q.push(make_pair(-0, k));
    
    
    int last = -1;
    while(!Q.empty())
    {
        int now, time;
        do
        {
            pair<int, int> temp = Q.top(); Q.pop();
            time = -temp.first;
            now = temp.second;
        }while(!Q.empty() && Check[now] == 1);
        if(Check[now] == 1) break;
        last = time;
        Check[now] = 1;
        
        for(int l : V[now])
        {
            int next = -1, cost = -1;
            for(int i=0; i<2; i++)
                if(L[l].x[i] == now)
                {
                    L[l].t[i] = time;
                    next = L[l].x[1-i];
                    cost = L[l].c;
                }
//            printf("line %d %d\n", next, cost);
            if(Check[next] == 1) continue;
            Q.push(make_pair(-time-cost, next));
        }
    }
    
    int sum = 0;
    for(int i=1; i<=M; i++)
    {
        int how = (last - L[i].t[0]) + (last - L[i].t[1]);
        if(how < L[i].c)
        {
            sum = max(sum, (L[i].c - how));
        }
    }
    
//    printf("%d : %d [%d / %d]\n", k, sum + last * 2, sum, last);
    return sum + last * 2;
}

int main()
{
    scanf("%d%d", &N, &M);
    
    for(int i=1; i<=M; i++)
    {
        scanf("%d%d%d", &L[i].x[0], &L[i].x[1], &L[i].c);
        V[ L[i].x[0] ].push_back( i );
        V[ L[i].x[1] ].push_back( i );
    }
    
    int result = 0x7fffffff;
    
    for(int i=1; i<=N; i++)
        result = min(result, Fire(i));
    
    if(result % 2 == 1)
        printf("%d.5\n", result/2);
    else
        printf("%d.0\n", result/2);
    
    return 0;
}




