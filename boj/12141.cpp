//
//  main.cpp
//  B
//
//  Created by KJBS2 on 2015. 5. 30..
//  Copyright (c) 2015년 KJBS2. All rights reserved.
//

#include <stdio.h>

#define MAX_N 200

double V, X;
int N;
struct POOL{
    double R;
    double C;
}P[MAX_N];

double Mymax(double x, double y) {
    if(x>y) return x;
    return y;
}

void Process(int t) {
    scanf("%d%lf%lf", &N, &V, &X);
    for(int i=1; i<=N; i++) {
        scanf("%lf%lf", &P[i].R, &P[i].C);
    }
    
    if(N==1) {
        if(X != P[1].C)
            printf("Case #%d: IMPOSSIBLE\n", t);
        else
            printf("Case #%d: %lf\n", t, V/P[1].R);

    }
    
    
    if(N==2) {
        if(P[1].C == P[2].C) {
            if(X != P[1].C)
                printf("Case #%d: IMPOSSIBLE\n", t);
            else
                printf("Case #%d: %.9lf\n", t, V/(P[1].R + P[2].R));
            
            return;
        }
        double t1 = (X*V-V*P[2].C) / (P[1].R * (P[1].C - P[2].C));
        double t2 = (V*P[1].C-X*V) / (P[2].R * (P[1].C - P[2].C));
//        printf("%lf %lf\n", t1, t2);
        
        if(t1 < 0 || t2 < 0) {
            printf("Case #%d: IMPOSSIBLE\n", t);
            return;
        }
        
        printf("Case #%d: %.9lf\n", t, Mymax(t1, t2));
        
    }
    return;
}

int main() {
    int T; scanf("%d", &T);
    for(int t=1; t<=T; t++)
        Process(t);
    
    return 0;
}