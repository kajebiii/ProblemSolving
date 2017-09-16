//
//  main.cpp
//
//  Created by KJBS2 on 6/1/16.
//  Copyright © 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

const int MAX_N = 50;

int N, M;
vector<int> V[MAX_N];
int UnF[MAX_N];
void SetUnF(int k)
{
    UnF[k] = k;
}
int Find(int k)
{
    return UnF[k] == k ? k : UnF[k] = Find(UnF[k]);
}
void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if(a == b) return;
    UnF[b] = a;
}

int Answer[MAX_N];
void PROCESS()
{
    int cnt = 0;
    int dif = M - (N-1);
    
    for(int i=0; i<N; i++)
        SetUnF(i);
    for(int i=0; i<N; i++)
    {
        for(int j : V[i])
        {
            if(Find(i) == Find(j))
            {
                if(dif > 0)
                {
                    dif = dif - 1;
                    Answer[i]++;
                    Answer[j]++;
                }
                continue;
            }
            Union(i, j);
            Answer[i]++;
            Answer[j]++;
            cnt++;
        }
    }
    
    if(cnt != (N-1) || dif != 0)
    {
        printf("-1\n");
        return;
    }
    
    for(int i=0; i<N; i++)
        printf("%d ", Answer[i]);
}

void INPUT()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
    {
        char nowI[MAX_N];
        scanf("%s", nowI);
        for(int j=0; j<N; j++)
            if(nowI[j] == 'Y' && j >= i)
                V[i].push_back(j);
    }
    return;
}

int main()
{
    INPUT();
    PROCESS();
    
    
    return 0;
}




