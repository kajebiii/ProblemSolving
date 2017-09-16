//
//  main.cpp
//
//  Created by KJBS2 on 5/28/16.
//  Copyright © 2016 KJBS2. All rights reserved.
//
 
#include <stdio.h>
#include <queue>
 
using namespace std;
 
const int MAX_N = 150;
 
int N, M, K;
int Map[MAX_N*2][MAX_N*2];
int Line[MAX_N*2][MAX_N*2][4];
char Data[MAX_N*2][MAX_N*2];
bool DataCheck[MAX_N*2][MAX_N*2];
bool Check[MAX_N*MAX_N*4];
 
 
void setMap(int i, int j, int cnt)
{
    Map[i/2*2][j/2*2] = Map[i/2*2+1][j/2*2] = Map[i/2*2][j/2*2+1] = Map[i/2*2+1][j/2*2+1] = cnt;
}
 
int main() {
    double inputK;
    scanf("%d%d%lf", &N, &M, &inputK);
    K = (inputK * 2 + 0.5);
     
    for(int i=2*M; i>=0; i--)
        scanf("%s", Data[i]);
     
    int cnt = 0;
    for(int i=0; i<=2*M; i++)
        for(int j=0; j<=2*N; j++)
        {
            int ChangeX[4] = {0, 1, 0, -1};
            int ChangeY[4] = {1, 0, -1, 0};
            if(DataCheck[i][j] == true) continue;
            if(Data[i][j] != 'B') continue;
            queue<pair<int, int>> Q;
            ++cnt;
            Q.push(make_pair(i, j));
            DataCheck[i][j] = true;
            while(!Q.empty())
            {
                pair<int, int> now = Q.front(); Q.pop();
                if(Data[now.first][now.second] == 'B')
                    setMap(now.first, now.second, cnt);
                for(int k=0; k<4; k++)
                {
                    int x = now.first  + ChangeX[k];
                    int y = now.second + ChangeY[k];
                    if(x<0 || x>=2*M || y<0 || y>=2*N) continue;
                    if(DataCheck[x][y] == true) continue;
                    if(Data[x][y] != 'B' && Data[x][y] != '.') continue;
                    Q.push(make_pair(x, y));
                    DataCheck[x][y] = true;
                }
            }
        }
     
     
    int X = K-1, Y = 0;
    N*=2;
    M*=2;
     
     
    int result = 0;
 
    while(Y < 2*M)
    {
        int k = 0, nowX = X, nowY = Y;
        while(nowX < 0)
        {
            k++;
            nowX += N;
        }
        if(k % 2 == 1)
        {
            nowX = (N-1) - nowX;
        }
        if(nowY >= M)
        {
            nowY = 2*M - 1 - nowY;
        }
         
        if(Check[Map[nowY][nowX]] == false)
        {
            Check[Map[nowY][nowX]] = true;
            if(Map[nowY][nowX] != 0)
                result ++;
        }
        X -= 1;
        Y += 1;
    }
     
    printf("%d\n", result);
     
    return 0;
}