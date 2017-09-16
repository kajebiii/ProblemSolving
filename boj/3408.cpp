//
//  main.cpp
//  3408
//
//  Created by KJBS2 on 2016. 8. 5..
//  Copyright © 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int MAX_N = 2e5;

int N, Nr[MAX_N + 1];

map<int, int> ReNum; int maxNr = 0;
map<int, int>::iterator it;
vector<int> Index[MAX_N + 1]; // ReNum들이 어디에
int Where[MAX_N + 1]; // 각각의 값이 Index[ReNum]의 어디에
int Check[MAX_N + 1][2];
int Wall[MAX_N + 1];

bool isBoring(int a, int b)
{
    if(a >= b) return false;
    
    set<int> S;
    set<int>::iterator it;
    
    for(int i=a; i<=b; i++)
        Check[Nr[i]][0] = Check[Nr[i]][1] = -1;
    for(int i=a; i<=b; i++)
    {
        if(Check[Nr[i]][0] == -1)
        {
            Check[Nr[i]][0] = Where[i];
            Check[Nr[i]][1] = Where[i];
            continue;
        }
        Check[Nr[i]][1] = Where[i];
    }
    
    for(int i=a; i<=b; i++)
    {
        if(Check[Nr[i]][0] != Check[Nr[i]][1])
            continue;
        S.insert(i);
//        printf("insert %d\n", i);
    }
    
    int r = a, f = b;
    while(S.size() != 0 && r <= f)
    {
        int m = (r+f)/2;
        it = S.begin();
        int now = *it;
//        printf("now is %d [%d %d]\n", now, r, f);
        if(now <= m)
        {
            S.erase(it);
            Wall[now] = 1;
            for(int i=r; i<=now; i++)
            {
                Check[Nr[i]][0]++;
                if(Check[Nr[i]][0] == Check[Nr[i]][1] && Index[Nr[i]][Check[Nr[i]][0]] > now)
                    S.insert(Index[Nr[i]][Check[Nr[i]][0]]);
            }
            r = now + 1;
        }
        else
        {
            it = S.end(); it--;
            now = *it;
            S.erase(it);
            Wall[now] = 1;
            for(int i=f; i>=now; i--)
            {
                Check[Nr[i]][1]--;
                if(Check[Nr[i]][0] == Check[Nr[i]][1] && Index[Nr[i]][Check[Nr[i]][0]] < now)
                    S.insert(Index[Nr[i]][Check[Nr[i]][0]]);
            }
            f = now - 1;
        }
    }
    
    bool result = false;
    int x = -1;
    for(int i=a; i<=b; i++)
    {
        if(Wall[i] == 1)
        {
            if(x == -1)
            {
                x = i;
                if(isBoring(a, x-1))
                {
                    result = true;
                }
                continue;
            }
            if(isBoring(x+1, i-1))
            {
                result = true;
            }
            x = i;
        }
        if(i == b)
        {
            if(x == -1)
            {
                result = true;
                continue;
            }
            if(isBoring(x+1, b))
            {
                result = true;
            }
        }
    }
//    printf("%d %d : %d\n", a, b, (int)result);
    
    return result;
}

void Task_Main()
{
    ReNum.clear();
    maxNr = 0;
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &Nr[i]);
        
        it = ReNum.find(Nr[i]);
        if(it == ReNum.end())
            ReNum[Nr[i]] = ++maxNr;
    }
    for(int i=1; i<=N; i++) {
        Nr[i] = ReNum[Nr[i]];
        Index[Nr[i]].push_back(i);
        Where[i] = (int)Index[Nr[i]].size() - 1;
    }
    for(int i=1; i<=N; i++)
        Wall[i] = 0;
    
    
    if(isBoring(1, N))
        printf("boring\n");
    else
        printf("non-boring\n");
    
    for(int i=1; i<=N; i++)
    {
        Index[i].clear();
        Index[i].shrink_to_fit();
    }
    
    return;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int i=0; i<T; i++)
        Task_Main();
    
    return 0;
}



