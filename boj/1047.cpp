//
//  main.cpp
//  1047
//
//  Created by KJBS2 on 2016. 8. 3..
//  Copyright © 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 40;

struct TREE
{
    int x;
    int y;
    int l;
    const bool operator<(const TREE &other) const
    {
        return l > other.l;
    }
};

int N;
TREE T[MAX_N];
int Xs[MAX_N], XN;
int Ys[MAX_N], YN;

bool isBetween(int k, int x, int y)
{
    if(k < x || k > y) return false;
    return true;
}

void INPUT()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%d%d%d", &T[i].x, &T[i].y, &T[i].l);
        Xs[i] = T[i].x;
        Ys[i] = T[i].y;
    }
    sort(T, T + N);
    sort(Xs, Xs + N);
    sort(Ys, Ys + N);
    XN = (int)(unique(Xs, Xs + N) - Xs);
    YN = (int)(unique(Ys, Ys + N) - Ys);
}

void PROCESS()
{
    int result = N;
    for(int i0=0; i0<XN; i0++)
        for(int i1=i0; i1<XN; i1++)
            for(int j0=0; j0<YN; j0++)
                for(int j1=j0; j1<YN; j1++)
                {
                    int sumL = 0;
                    int cnt = 0;
                    for(int i=0; i<N; i++)
                    {
                        if(!isBetween(T[i].x, Xs[i0], Xs[i1]) || !isBetween(T[i].y, Ys[j0], Ys[j1]))
                        {
                            sumL += T[i].l;
                            cnt = cnt + 1;
                        }
                    }
                    for(int i=0; i<N; i++)
                    {
                        if( isBetween(T[i].x, Xs[i0], Xs[i1]) &&  isBetween(T[i].y, Ys[j0], Ys[j1]))
                        {
                            if(sumL < 2*(Xs[i1] - Xs[i0] + Ys[j1] - Ys[j0]))
                            {
                                sumL += T[i].l;
                                cnt = cnt + 1;
                            }
                        }
                    }
                    if(sumL >= 2*(Xs[i1] - Xs[i0] + Ys[j1] - Ys[j0]))
                        result = min(result, cnt);
                }
    printf("%d", result);
}

int main()
{
    INPUT();
    PROCESS();
    
    return 0;
}