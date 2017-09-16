//
//  main.cpp
//
//  Created by KJBS2 on 5/31/16.
//  Copyright © 2016 KJBS2. All rights reserved.
//


#include <stdio.h>
#include <vector>

using namespace std;

const int MAX_N = 50 + 1;

int N, M, KN;
int Know[MAX_N], UnF[MAX_N];
bool True[MAX_N];
int Find(int x)
{
    return UnF[x] == x ? x : UnF[x] = Find(UnF[x]);
}
bool IsKnow(int x)
{
    return True[Find(x)];
}
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x == y) return;
    UnF[x] = y;
}

vector<int> V[MAX_N];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
        UnF[i] = i;
    
    scanf("%d", &KN);
    for(int i=1; i<=KN; i++)
        scanf("%d", &Know[i]);
    
    for(int m=1; m<=M; m++)
    {
        int nowN;
        scanf("%d", &nowN);
        if(nowN == 0) continue;
        int past, now;
        scanf("%d", &past);
        V[m].push_back(past);
        for(int i=2; i<=nowN; i++)
        {
            scanf("%d", &now);
            V[m].push_back(now);
            Union(past, now);
            past = now;
        }
    }
    
    for(int i=1; i<=KN; i++)
        True[Find(Know[i])] = true;
    
    int result = 0;
    for(int i=1; i<=M; i++)
    {
        bool canLie = true;
        for(int nr : V[i])
        {
            if(True[Find(nr)] == false) continue;
            canLie = false;
            break;
        }
        if(canLie == true)
            result = result + 1;
    }
    
    printf("%d\n", result);
    
    return 0;
}










