//
//  main.cpp
//  1050
//
//  Created by KJBS2 on 2016. 8. 3..
//  Copyright © 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAX_N = 300;
const int MAX_W = 50;
const int MOD = 1e9 + 7;

int N, M, L, W;
char Word[MAX_W];
char Map[MAX_N + 1][MAX_N + 1];
int Dy[MAX_W + 1][MAX_N + 1][MAX_N + 1];
int SumDy[MAX_N + 1][MAX_N + 1];

int Plus(int x, int y)
{
    return ((x + y) % MOD + MOD) % MOD;
}

int Get(int array[][MAX_N + 1], int x, int y)
{
    if(x <= 0 || y <= 0)
        return 0;
    if(x >  N || y >  M)
        return 0;
    return array[x][y];
}

void INPUT()
{
    scanf("%d%d%d\n", &N, &M, &L);
    scanf("%s", Word + 1);
    W = (int)strlen(Word + 1);
    
    for(int i=1; i<=N; i++)
        scanf("%s", Map[i] + 1);

    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            if(Map[i][j] == Word[1])
                Dy[1][i][j] = 1;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            SumDy[i][j] = Plus(Plus(Dy[1][i][j], SumDy[i-1][j]), Plus(SumDy[i][j-1], -SumDy[i-1][j-1]));
    
}

int main()
{
    INPUT();
    
    for(int w=2; w<=W; w++)
    {
        for(int i=1; i<=N; i++)
            for(int j=1; j<=M; j++)
                if(Map[i][j] == Word[w])
                {
                    if(i >= 3 && j >= 3)
                    {
                        Dy[w][i][j] = Plus(Dy[w][i][j], +Get(SumDy  , i-2, j-2));
                        Dy[w][i][j] = Plus(Dy[w][i][j], -Get(Dy[w-1], i-2, j-2));
                    }
                    
                    if(i >= 3 && j <= M - 2)
                    {
                        Dy[w][i][j] = Plus(Dy[w][i][j], +Get(SumDy  , i-2, M  ));
                        Dy[w][i][j] = Plus(Dy[w][i][j], -Get(SumDy  , i-2, j+1));
                        Dy[w][i][j] = Plus(Dy[w][i][j], -Get(Dy[w-1], i-2, j+2));
                    }

                    if(i <= N - 2 && j >= 3)
                    {
                        Dy[w][i][j] = Plus(Dy[w][i][j], +Get(SumDy  , N  , j-2));
                        Dy[w][i][j] = Plus(Dy[w][i][j], -Get(SumDy  , i+1, j-2));
                        Dy[w][i][j] = Plus(Dy[w][i][j], -Get(Dy[w-1], i+2, j-2));
                    }

                    if(i <= N - 2 && j <= M - 2)
                    {
                        Dy[w][i][j] = Plus(Dy[w][i][j], +Get(SumDy  , N  , M  ));
                        Dy[w][i][j] = Plus(Dy[w][i][j], -Get(SumDy  , i+1, M  ));
                        Dy[w][i][j] = Plus(Dy[w][i][j], -Get(SumDy  , N  , j+1));
                        Dy[w][i][j] = Plus(Dy[w][i][j], +Get(SumDy  , i+1, j+1));
                        Dy[w][i][j] = Plus(Dy[w][i][j], -Get(Dy[w-1], i+2, j+2));
                    }
                    
                }
        for(int i=1; i<=N; i++)
            for(int j=1; j<=M; j++)
                SumDy[i][j] = Plus(Plus(Dy[w][i][j], SumDy[i-1][j]), Plus(SumDy[i][j-1], -SumDy[i-1][j-1]));
    }
    
    printf("%d\n", SumDy[N][M]);
    
    return 0;
}








