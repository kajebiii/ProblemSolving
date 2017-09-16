//
//  main.cpp
//  3
//
//  Created by KJBS2 on 6/21/16.
//  Copyright © 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = (1e2) + 1;
const int MAX_V = (1e3) + 1;

int N, V, E;
int A[2], Knight[MAX_N];
vector< pair<int, int> > Ver[MAX_V];

int Dis[2][MAX_V];
bool Check[MAX_V];


priority_queue< pair<int, int> > PQ;

int main()
{
    scanf("%d%d%d", &N, &V, &E);
    scanf("%d%d", &A[0], &A[1]);
    for(int i=1; i<=N; i++)
        scanf("%d", &Knight[i]);
    for(int i=1; i<=E; i++)
    {
        int a, b, l;
        scanf("%d%d%d", &a, &b, &l);
        Ver[a].push_back(make_pair(l, b));
        Ver[b].push_back(make_pair(l, a));
    }
    
    for(int k=0; k<2; k++)
    {
        for(int i=1; i<=V; i++)
        {
            Dis[k][i] = -1;
            Check[i] = false;
        }
        Dis[k][A[k]] = 0;
        
        PQ.push(make_pair(0, A[k]));
        
        while(!PQ.empty())
        {
            int dis, now;
            do
            {
                dis = -PQ.top().first;
                now = PQ.top().second;
                PQ.pop();
            }while(Check[now] == true && !PQ.empty());

            if(Check[now] == true) break;
            Check[now] = true;
            Dis[k][now] = dis;
            
            for(int i=0; i<Ver[now].size(); i++)
            {
                int cost = Ver[now][i].first;
                int next = Ver[now][i].second;
                if(Check[next] == true) continue;
                PQ.push(make_pair(-dis-cost, next));
            }
        }
    }
    
    int result = 0;
    for(int i=1; i<=N; i++)
        result += (Dis[0][Knight[i]] + Dis[1][Knight[i]]);
    
    printf("%d\n", result);
        
    
    return 0;
}