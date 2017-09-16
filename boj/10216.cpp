//
//  main.cpp
//  10216
//
//  Created by KJBS2 on 5/27/16.
//  Copyright © 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <queue>

using namespace std;

const int MAX_N = 3000;

int N;
struct TOWER{
    int x, y;
    int r;
}Tower[MAX_N];
bool Check[MAX_N];

bool IsConnect(int x, int y) {
    int max_square =  (Tower[x].r + Tower[y].r) * (Tower[x].r + Tower[y].r);
    int dis_square =  (Tower[x].x - Tower[y].x) * (Tower[x].x - Tower[y].x)
                    + (Tower[x].y - Tower[y].y) * (Tower[x].y - Tower[y].y);
    
    return dis_square <= max_square;
}

void Process() {
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d%d%d", &Tower[i].x, &Tower[i].y, &Tower[i].r);
    
    for(int i=0; i<N; i++)
        Check[i] = false;

    int result = 0;
    queue<int> Q;
    for(int k=0; k<N; k++)
    {
        if(Check[k] == true) continue;
        result = result + 1;
        Q.push(k);
        Check[k] = true;
        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for(int next=0; next<N; next++)
            {
                if(Check[next] == true) continue;
                if(IsConnect(now, next) == false) continue;
                Q.push(next);
                Check[next] = true;
            }
        }
    }
    printf("%d\n", result);
}

int main() {
    int T;
    scanf("%d", &T);
    for(int i=0; i<T; i++)
        Process();
    return 0;
}











