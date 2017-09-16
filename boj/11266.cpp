//
//  main.cpp
//  11266
//
//  Created by KJBS2 on 2016. 8. 7..
//  Copyright © 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e4 + 10;

int N, M;
vector<int> V[MAX_N];
vector<int> Ans;

int Nr = 0;
int dfn[MAX_N], low[MAX_N];

void Find(int u, int v)
{
    dfn[u] = low[u] = ++Nr;
    
    bool isThis = false;
    
    int cnt = 0;
    for(int w : V[u])
    {
        if(w == v) continue;
        if(dfn[w] == 0)
        {
            Find(w, u);
            cnt++;
            low[u] = min(low[u], low[w]);
            if(dfn[u] <= low[w])
                isThis = true;
        }
        else
            low[u] = min(low[u], dfn[w]);
    }
    
    if(v != -1 && isThis)
        Ans.push_back(u);
    if(v == -1 && cnt >= 2)
        Ans.push_back(u);
}

int main()
{
    scanf("%d%d", &N, &M);
    
    for(int i=0; i<M; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        V[x].push_back(y);
        V[y].push_back(x);
    }
    
    for(int i=1; i<=N; i++)
        if(dfn[i] == 0)
        {
            Find(i, -1);
        }
    
    sort(Ans.begin(), Ans.end());
    
    printf("%d\n", (int)Ans.size());
    for(int ans : Ans)
        printf("%d ", ans);
    
    return 0;
}






