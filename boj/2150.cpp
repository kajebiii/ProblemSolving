//
//  main.cpp
//  1325
//
//  Created by KJBS2 on 2016. 8. 7..
//  Copyright © 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e4 + 10;
const int MAX_M = 1e5 + 10;

vector<int> V[MAX_N];

int N, M;

/* SCC */
vector<int> stk;
int dfN, grN;
int dfn[MAX_N], low[MAX_N], grp[MAX_N], rep[MAX_N];
vector< vector<int> > Group;

void scc(int v)
{
    dfn[v] = low[v] = ++dfN;
    stk.push_back(v);
    
    for(int w : V[v])
    {
        if(dfn[w] == 0)
        {
            scc(w);
            low[v] = min(low[v], low[w]);
        }
        else if(grp[w] == 0)
        {
            low[v] = min(low[v], dfn[w]);
        }
    }
    
    if(dfn[v] == low[v])
    {
        rep[++grN] = v;
        Group.push_back(vector<int>());
                        
        while(true)
        {
            int now = stk.back(); stk.pop_back();
            grp[now] = grN;
            Group.back().push_back(now);
            if(now == v) break;
        }
    }
}
/* SCC */



int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<M; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        
        V[y].push_back(x);
    }
    
    dfN = grN = 0;
    for(int i=1; i<=N; i++)
        dfn[i] = low[i] = grp[i] = rep[i] = 0;
    for(int i=1; i<=N; i++)
        if(dfn[i] == 0)
        {
            stk.clear();
            scc(i);
        }
    
    for(vector<int> &V : Group)
        sort(V.begin(), V.end());
    sort(Group.begin(), Group.end());
    printf("%d\n", (int)Group.size());
    for(vector<int> &V : Group)
    {
        for(int k : V)
            printf("%d ", k);
        printf("-1\n");
    }
    
    
    
    
    return 0;
}















