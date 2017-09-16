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
#include <queue>

using namespace std;

const int MAX_N = 1e4 + 10;
//const int MAX_M = 1e5 + 10;

vector<int> V[MAX_N];
vector<int> GV[MAX_N];

int N, M;

/* SCC */
vector<int> stk;
int dfN, grN;
int dfn[MAX_N], low[MAX_N], grp[MAX_N], rep[MAX_N], cnt[MAX_N];
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
            cnt[grN]++;
            Group.back().push_back(now);
            if(now == v) break;
        }
    }
}
/* SCC */

queue<int> Q;
int chk[MAX_N];
int Fast[MAX_N];

int AnsMax = 0;
vector<int> Ans;


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
    
    for(int i=1; i<=N; i++)
        for(int j : V[i])
            GV[grp[i]].push_back(grp[j]);
    
    for(int k=1; k<=N; k++)
    {
        if(Fast[k] == 1) continue;
        while(!Q.empty()) Q.pop();
        for(int i=1; i<=N; i++)
            chk[i] = 0;
        Q.push(k);
        chk[k] = 1;
        
        int nowSum = 0;
        
        while(!Q.empty())
        {
            int now = Q.front(); Q.pop();
            Fast[now] = 1;
            nowSum += cnt[now];
            for(int next : GV[now])
            {
                if(chk[next] == 1) continue;
                Q.push(next);
                chk[next] = 1;
            }
        }
        
        if(AnsMax == nowSum)
            Ans.push_back(k);
        if(AnsMax < nowSum)
        {
            AnsMax = nowSum;
            Ans.clear();
            Ans.push_back(k);
        }
        
        
    }
    
//    printf("[%d]\n", AnsMax);
    vector<int> change;
    for(int x : Ans)
        for(int k : Group[x-1])
            change.push_back(k);
    sort(change.begin(), change.end());
    
    for(int x : change)
        printf("%d ", x);
    
    return 0;
}























