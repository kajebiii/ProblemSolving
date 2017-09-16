//
//  main.cpp
//  1050
//
//  Created by KJBS2 on 2016. 8. 4..
//  Copyright © 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 1e5;

int N;
int A[2][MAX_N + 1];
vector<int> Where[2][MAX_N + 1];
vector<int> V[MAX_N + 1];
queue<int> Q;


int UNF[MAX_N + 1];
int Cnt[MAX_N + 1];
int Check[MAX_N + 1];

int Find(int v)
{
    if(UNF[v] == 0)
        return v;
    return UNF[v] = Find(UNF[v]);
}
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x == y) return;
    UNF[y] = x;
}

int main()
{
    scanf("%d", &N);
    for(int j=0; j<2; j++)
        for(int i=1; i<=N; i++)
        {
            scanf("%d", &A[j][i]);
            Where[j][A[j][i]].push_back(i);
        }
    
    for(int i=1; i<=N; i++)
    {
        if(Where[0][i].size() + Where[1][i].size() >= 3)
        {
            printf("-1\n");
            return 0;
        }
        if(Where[0][i].size() == 1 && Where[1][i].size() == 1)
        {
            Union(Where[0][i][0], Where[1][i][0]);
        }
    }
    
    for(int i=1; i<=N; i++)
    {
        Cnt[Find(i)]++;
    }
    
    for(int i=1; i<=N; i++)
    {
        for(int j=0; j<2; j++)
            if(Where[j][i].size() == 2)
            {
                V[ Find(Where[j][i][0]) ].push_back( Find(Where[j][i][1]) );
                V[ Find(Where[j][i][1]) ].push_back( Find(Where[j][i][0]) );
            }
    }
    
    int result = 0;
    
    for(int i=1; i<=N; i++)
    {
        if(V[i].size() == 0) continue;
        if(Check[i] == 1) continue;
        
        while(!Q.empty()) Q.pop();
        
        Check[i] = 1;
        Q.push(i);
        
        int cnt = 0;
        int two = 0;
        int sum = 0;
        
        while(!Q.empty())
        {
            int now = Q.front(); Q.pop();
//            printf("now : %d\n", now);
            cnt++;
            sum += Cnt[now];
            if(cnt % 2 == 0)
                two += Cnt[now];
            for(int k=0; k<V[now].size(); k++)
            {
                if(Check[V[now][k]] == 1) continue;
                Q.push(V[now][k]);
                Check[V[now][k]] = 1;
                break;
            }
        }
        
//        printf("%d %d %d\n", cnt, two, sum);
        
        if(cnt % 2 == 1)
        {
            printf("-1\n");
            return 0;
        }
        int nowMin = min(two, sum - two);
        result += nowMin;
    }
    
    printf("%d\n", result);
    
        
    return 0;
}





