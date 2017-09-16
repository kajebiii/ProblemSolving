//
//  main.cpp
//  B
//
//  Created by KJBS2 on 2016. 8. 6..
//  Copyright © 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 3e5 + 30;

int N;

struct SEAT
{
    int A[10];
    const bool operator<(const SEAT &other) const
    {
        for(int i=1; i<=9; i++)
            if(A[i] < other.A[i])
                return true;
            else if(A[i] > other.A[i])
                return false;
        
        return false;
    }
}S[MAX_N];

int Fast[MAX_N][10];

pair<int, int> Find(int a, int b, int k, int wh)
{
    int x = a, y = b;
    
    while(x <= b)
    {
        if(S[x].A[wh] == k)
        {
            y = min(y, Fast[x][wh] - 1);
            break;
        }
        else
        {
            x = Fast[x][wh];
        }
    }
    return make_pair(x, y);
    
}
/*
pair<int, int> Find2(int a, int b, int k, int wh)
{
    int r, m, f;
    r = a;
    f = b;
    
    int minI = b+1, maxI = a-1;
    while(r <= f)
    {
        m = (r + f) / 2;
        if(S[m].A[wh] == k)
        {
            minI = m;
            f = m - 1;
        }
        else if(S[m].A[wh] > k)
        {
            f = m - 1;
        }
        else if(S[m].A[wh] < k)
        {
            r = m + 1;
        }
    }
    
    r = a;
    f = b;
    while(r <= f)
    {
        m = (r + f) / 2;
        if(S[m].A[wh] == k)
        {
            maxI = m;
            r = m + 1;
        }
        else if(S[m].A[wh] > k)
        {
            f = m - 1;
        }
        else if(S[m].A[wh] < k)
        {
            r = m + 1;
        }
    }
    
    return make_pair(minI, maxI);
}
*/
int Choose[10];
vector< pair<int, int> > V[10];

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=9; j++)
            scanf("%d", &S[i].A[j]);
    
    sort(S+1, S+N+1);
    
    for(int j=1; j<=9; j++)
        S[N+1].A[j] = 0;
    
    for(int j=1; j<=9; j++)
    {
        int last = 1;
        for(int i=1; i<=N; i++)
        {
            if(S[i].A[j] != S[i+1].A[j])
            {
                for(int k=last; k<=i; k++)
                    Fast[k][j] = i+1;
                last = i+1;
            }
        }
    }
    /*
    for(int i=1; i<=N; i++, printf("\n"))
        for(int j=1; j<=9; j++)
            printf("%d ", S[i].A[j]);
    printf("\n");
    for(int i=1; i<=N; i++, printf("\n"))
        for(int j=1; j<=9; j++)
            printf("%d ", Fast[i][j]);
    */
    
    int resultMin = N, resultMax = 0;
    
    for(int o=0; o<19683; o++)
    {
        int test = o;
        for(int i=1; i<=9; i++)
        {
            Choose[i] = test % 3 + 1;
            test /= 3;
        }
        
        V[0].push_back(make_pair(1, N));
        
        for(int i=1; i<=9; i++)
        {
            for(pair<int, int> ix : V[i-1])
                for(int n=1; n<=3; n++)
                {
                    if(Choose[i] == n) continue;
                    pair<int, int> now = Find(ix.first, ix.second, n, i);
                    if(now.first <= now.second)
                    {
                        V[i].push_back(now);
                    }
                }
        }
        
        int nowSize = 0;
        
        for(pair<int, int> ii : V[9])
            nowSize += (ii.second - ii.first + 1);
        
        resultMin = min(resultMin, nowSize);
        resultMax = max(resultMax, nowSize);
        
        for(int i=0; i<=9; i++)
        {
            V[i].clear();
            V[i].shrink_to_fit();
        }
    }
    
    printf("%d %d\n", resultMin, resultMax);
    
    return 0;
}















