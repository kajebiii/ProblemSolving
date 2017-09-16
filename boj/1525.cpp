//
//  main.cpp
//  1525
//
//  Created by KJBS2 on 2016. 8. 7..
//  Copyright © 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <map>
#include <queue>

using namespace std;

int Cnt = 0;
map<long long, int> M;

bool Check(long long x)
{
    if(M.count(x) == 0)
    {
        M[x] = Cnt++;
        return false;
    }
    return true;
}

queue< pair<long long, int> > Q;

int main()
{
    long long first = 0;
    int A[9];
    for(int i=0; i<9; i++)
    {
        scanf("%d", &A[i]);
        first *= 10;
        first += 1ll * A[i];
    }
    
    Q.push(make_pair(first, 0));
    
    long long Ans = 0;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        {
            Ans *= 10;
            if(i != 2 || j != 2)
                Ans += 1ll * (i * 3 + j + 1);
        }
    
    
    while(!Q.empty())
    {
        int now[3][3];
        long long nowll = Q.front().first;
        int how = Q.front().second;
        
        Q.pop();
        
        if(nowll == Ans)
        {
            printf("%d\n", how);
            return 0;
        }
        
        int zX = -1, zY = -1;
        for(int i=2; i>=0; i--)
            for(int j=2; j>=0; j--)
            {
                now[i][j] = nowll % 10;
                nowll /= 10;
                if(now[i][j] == 0)
                {
                    zX = i;
                    zY = j;
                }
            }
        
        
        int cX[4] = {-1, 0, 1, 0};
        int cY[4] = {0, -1, 0, 1};
        for(int k=0; k<4; k++)
        {
            long long next = 0;
            int nx = zX + cX[k];
            int ny = zY + cY[k];
            
            if(nx < 0 || ny < 0 || nx >= 3 || ny >= 3) continue;
            
            for(int i=0; i<3; i++)
                for(int j=0; j<3; j++)
                {
                    int x = now[i][j];
                    if(i == nx && j == ny)
                        x = now[zX][zY];
                    if(i == zX && j == zY)
                        x = now[nx][ny];
                    next *= 10;
                    next += 1ll * x;
                }
            
            if(Check(next) == false)
                Q.push(make_pair(next, how + 1));
        }
    }
    
    printf("-1");
    
    return 0;
}






















