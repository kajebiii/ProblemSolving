//
//  main.cpp
//  C
//
//  Created by KJBS2 on 2016. 8. 6..
//  Copyright © 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N;
struct VOTE
{
    int a, b;
    const bool operator<(const VOTE &other) const
    {
        return max(a, b) < max(other.a, other.b);
    }
}R[1111];

vector<int> V[100010];
set<int> S;
set<int>::iterator it;

long long getAns(int L, int A, int B)
{
//    printf("%d %d %d\n", L, A, B);
    long long result = 0;
    for(it = S.end(), it--; it != S.begin(); it--)
    {
        int sum = *it;
        for(int i : V[sum])
        {
            if(i <= L)
            {
                A -= R[i].a;
                B -= R[i].b;
            }
        }
        
        if(A > B)
        {
            it--;
            int diff = sum - *it;
//            printf("<%d [%d %d]\n", diff, A, B);
            it++;
            result += diff;
        }
    }
    return result;
}

int main()
{

    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d%d", &R[i].a, &R[i].b);
    R[N+1].a = R[N+1].b = 1000000;
    sort(R+1, R+N+1);
    for(int i=1; i<=N; i++)
    {
        V[R[i].a + R[i].b].push_back(i);
        S.insert(R[i].a + R[i].b);
    }
    S.insert(0);
    S.insert(100000);
    
    int nowA = 0, nowB = 0;
    for(int i=1; i<=N; i++)
    {
        nowA += R[i].a;
        nowB += R[i].b;
    }
    
    long long result = 0;
    
    result += getAns(N, nowA, nowB) * (100000 - max(R[N].a, R[N].b));
    nowA -= R[N].a; nowB -= R[N].b;
    
    for(int i=N-1; i>=1; i--)
    {
        if(R[i] < R[i+1])
            result += getAns(i, nowA, nowB) * (max(R[i+1].a, R[i+1].b) - max(R[i].a, R[i].b));
        
        nowA -= R[i].a; nowB -= R[i].b;
    }
    
    printf("%lld\n", result);
    
    return 0;
}







