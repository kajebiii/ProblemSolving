//
//  main.cpp
//  1053
//
//  Created by KJBS2 on 2016. 8. 6..
//  Copyright © 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAX_N = 99;

int N;
char A[MAX_N];
int Change[MAX_N];
int D[MAX_N][MAX_N];

char getC(int k)
{
    return A[Change[k]];
}

int getResult()
{
    for(int i=1; i<=N; i++)
        D[i][i] = 0;
    
    for(int k=1; k<N; k++)
        for(int i=1; i<=N-k; i++)
        {
            int j = i + k;
            D[i][j] = min(min(D[i][j-1] + 1, D[i+1][j] + 1), D[i+1][j-1] + 1);
            
            
            if(getC(i) == getC(j))
                D[i][j] = min(D[i][j], D[i+1][j-1]);
            
        }
    
    return D[1][N];
}

int main()
{
    scanf("%s", A+1);
    N = (int)strlen(A+1);
    for(int i=1; i<=N; i++)
        Change[i] = i;
    
    int result = 2 * N;
    result = min(result, getResult());

    for(int i=1; i<=N; i++)
        for(int j=i+1; j<=N; j++)
        {
            Change[i] = j;
            Change[j] = i;
            result = min(result, getResult() + 1);
            Change[i] = i;
            Change[j] = j;
        }

    printf("%d\n", result);
    
    return 0;
}






