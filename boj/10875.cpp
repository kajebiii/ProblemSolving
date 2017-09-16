//
//  main.cpp
//  10875
//
//  Created by KJBS2 on 2016. 8. 7..
//  Copyright © 2016년 KJBS2. All rights reserved.
//


#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int MAX_N = 1e3 + 30;
const int INF = 0x7fffffff;

int L, N;

struct POINT
{
    int x, y;
    POINT()
    {
        x = y = 0;
    }
    POINT(int a, int b)
    {
        x = a;
        y = b;
    }
    POINT operator*(int t)
    {
        return POINT(x * t, y * t);
    }
    POINT operator+(POINT other)
    {
        return POINT(x + other.x, y + other.y);
    }
};
struct LINE
{
    POINT p[2];
    LINE()
    {
        p[0].x = p[0].y = 0;
        p[1].x = p[1].y = 0;
    }
    LINE(POINT X, POINT Y)
    {
        p[0] = X;
        p[1] = Y;
    }
    LINE(int x0, int y0, int x1, int y1)
    {
        p[0].x = x0;
        p[0].y = y0;
        p[1].x = x1;
        p[1].y = y1;
    }
}Ls[MAX_N];
int LN;

POINT C[4] = {POINT(-1, 0), POINT(0, -1), POINT(1, 0), POINT(0, 1)};

int K = 2;
POINT nowP, nextP;
int Right(int k)
{
    return (k+3) % 4;
}
int Left(int k)
{
    return (k+1) % 4;
}

bool Between(int k, int x, int y)
{
    if(x <= k && k <= y) return true;
    if(y <= k && k <= x) return true;
    return false;
}

int Col(LINE X, LINE Y)
{
//    printf("[%d %d / %d %d] [%d %d / %d %d]\n", X.p[0].x,  X.p[0].y,  X.p[1].x,  X.p[1].y,
//           Y.p[0].x,  Y.p[0].y,  Y.p[1].x,  Y.p[1].y );
    if(X.p[0].x == X.p[1].x)
    {
        if(Y.p[0].x == Y.p[1].x)
        {
            if(X.p[0].x != Y.p[0].x) return -1;
            if(Between(X.p[1].y, Y.p[0].y, Y.p[1].y))
                return min( abs(Y.p[0].y - X.p[0].y), abs(Y.p[1].y - X.p[0].y) );
            if(Between(Y.p[1].y, X.p[0].y, X.p[1].y))
                return min( abs(Y.p[0].y - X.p[0].y), abs(Y.p[1].y - X.p[0].y) );
            return -1;
        }
        else
        {
            if(Between(X.p[0].x, Y.p[0].x, Y.p[1].x) && Between(Y.p[0].y, X.p[0].y, X.p[1].y))
                return abs(Y.p[0].y - X.p[0].y);
            return -1;
        }
    }
    else if(X.p[0].y == X.p[1].y)
    {
        if(Y.p[0].y == Y.p[1].y)
        {
            if(X.p[0].y != Y.p[0].y) return -1;
            if(Between(X.p[1].x, Y.p[0].x, Y.p[1].x))
                return min( abs(Y.p[0].x - X.p[0].x), abs(Y.p[1].x - X.p[0].x) );
            if(Between(Y.p[1].x, X.p[0].x, X.p[1].x))
                return min( abs(Y.p[0].x - X.p[0].x), abs(Y.p[1].x - X.p[0].x) );
            return -1;
        }
        else
        {
            if(Between(X.p[0].y, Y.p[0].y, Y.p[1].y) && Between(Y.p[0].x, X.p[0].x, X.p[1].x))
                return abs(Y.p[0].x - X.p[0].x);
            return -1;
        }
    }
    printf("ERROR\n");
    return -1;
}


int main()
{
    scanf("%d%d", &L, &N);
    
    L++;
    Ls[++LN] = LINE(-L, -L, -L, +L);
    Ls[++LN] = LINE(-L, +L, +L, +L);
    Ls[++LN] = LINE(+L, -L, +L, +L);
    Ls[++LN] = LINE(-L, -L, +L, +L);
    Ls[++LN] = LINE( 0,  0,  0,  0);
    L--;
    
    long long Ans = 0;
    nowP.x = nowP.y  = 0;
    
    N++;
    
    for(int i=1; i<=N; i++)
    {
        int t; char c;
        if(i <= N-1)
            scanf("\n%d %c", &t, &c);
        else
        {
            t = 3 * L;
            c = 'R';
        }
        
        nextP = nowP + C[K] * t;
        nowP  = nowP + C[K] * 1;
        LINE now = LINE(nowP, nextP);
//        printf("%d %d\n", nextP.x, nextP.y);
        
        int col = INF;
        
        for(int j=1; j<=LN; j++)
        {
            int result = Col(now, Ls[j]);
//            printf("%d : %d\n", j, result);
            if(result == -1) continue;
            col = min(col, result);
        }
        if(col != INF)
        {
            Ans += 1ll * col;
            Ans += 1ll * 1;
            break;
        }
        Ans += t;
        
        Ls[++LN] = now;
        nowP = nextP;
//        printf("[%lld]\n\n", Ans);
        
        
        if(c == 'L')
            K = Left(K);
        else
            K = Right(K);
    }
    
    printf("%lld\n", Ans);
    
    return 0;
}














