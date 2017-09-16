//
//  main.cpp
//  10826
//
//  Created by KJBS2 on 2016. 8. 7..
//  Copyright © 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

typedef vector<int> VI;

VI Plus(VI &X, VI &Y)
{
    VI result;
    
    int nowN = 0;
    for(int i=0; i<X.size(); i++)
        if(nowN == i)
        {
            result.push_back(X[i]);
            nowN++;
        }

    for(int i=0; i<Y.size(); i++)
        if(nowN == i)
        {
            result.push_back(Y[i]);
            nowN++;
        }
        else
        {
            int k = i;
            result[i] += Y[i];
            while(result[k] >= 10)
            {
                if(nowN == (k+1) && result[k] >= 10)
                {
                    result.push_back(result[k] / 10);
                    nowN++;
                }
                else
                    result[k+1] += result[k] / 10;
                result[k] %= 10;
                k++;
            }
        }
            
    return result;
}

int main()
{
    int N;
    scanf("%d", &N);
    
    VI A[2];
    
    A[0].push_back(0);
    A[1].push_back(1);
    
    for(int i=2; i<=N; i++)
    {
        A[i%2] = Plus(A[i%2], A[1-i%2]);
        
    }
    for(int i = (int)A[N%2].size()-1; i>=0; i--)
        printf("%d", A[N%2][i]);
    
    return 0;
}










