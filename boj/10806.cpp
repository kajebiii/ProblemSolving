//
//  main.cpp
//  11400
//
//  Created by KJBS2 on 2016. 8. 7..
//  Copyright © 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

const int MAX_N = 1e5 + 10;

int N, M;
vector<int> V[MAX_N];
vector<int> R[MAX_N];
vector< pair<int, int> > Ans;

int Nr = 0;
int dfn[MAX_N], low[MAX_N], parent[MAX_N];
int Same[MAX_N];

int where(int u)
{
    if(Same[parent[u]] == 1)
        return u;
    return where(parent[u]);
}

void Merge(int u, int v)
{
//    printf("%d\n", u);
    Same[u] = 1;
    for(int w : R[u])
    {
        if(w == v) continue;
        Merge(w, u);
    }
}

deque<int> Find(int u, int v)
{
    dfn[u] = low[u] = ++Nr;
    parent[u] = v;
//    printf("%d %d\n", u, v);
    
    int cnt = 0;
    
    deque<int> result;
    
    for(int w : V[u])
    {
        if(w == v && cnt == 0)
        {
            cnt++;
            continue;
        }
        if(dfn[w] == 0)
        {
            deque<int> now = Find(w, u);
            low[u] = min(low[u], low[w]);
            if(dfn[u] < low[w])
            {
                if(now.size() == 0)
                {
                    now.push_back(w);
                }
//                Ans.push_back(make_pair(min(u, w), max(u, w) ));
            }
            else
            {
                R[u].push_back(w);
                R[w].push_back(u);
            }
            
            while(result.size() >= 1 && now.size() >= 1 && (result.size() + now.size()) >= 3 )
            {
                Ans.push_back(make_pair(min(result[0], now[0]), max(result[0], now[0]) ) );
                result.pop_front();
                now.pop_front();
            }
            while(now.size() >= 1)
            {
                result.push_back(now[0]);
                now.pop_front();
            }
            
        }
        else
            low[u] = min(low[u], dfn[w]);
    }
    /*
    printf("[%d] : ", u);
    for(int k : result)
        printf("%d ", k);
    printf("\n");
    */
    
    return result;
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
    
    deque<int> result = Find(1, -1);
    Merge(1, -1);
    if(result.size() == 2)
    {
        if(where(result[0]) == where(result[1]))
            for(int v : result)
                Ans.push_back(make_pair(min(v, 1), max(v, 1) ) );
        else
            Ans.push_back(make_pair(min(result[0], result[1]), max(result[0], result[1])  ) );
    }
    else
        for(int v : result)
            Ans.push_back(make_pair(min(v, 1), max(v, 1) ) );
    
    sort(Ans.begin(), Ans.end());
    
    printf("%d\n", (int)Ans.size());
    for(pair<int, int> ans : Ans)
        printf("%d %d\n", ans.first, ans.second);
    
    
    
    return 0;
}







