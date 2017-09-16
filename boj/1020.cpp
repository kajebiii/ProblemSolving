//
//  main.cpp
//  1020
//
//  Created by KJBS2 on 2/8/16.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAX_N = (int)2e1;
const int MAX_SUM = (int)2e2;
const long long INF = 1ll * 0x7fffffff * 0x7fffffff;

int N;
int Number[MAX_N];

void Input() {
    char charInput[MAX_N];
    scanf("%s", charInput + 1);
    N = (int)strlen(charInput + 1);
    
    for(int i=1; i<=N; i++)
        Number[i] = charInput[i] - '0';
    
    return;
}

int numberToCount[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 5};
long long sumToMinNumber[MAX_N][MAX_SUM];

int Answer[MAX_N];

void Process() {
    for(int i=0; i<MAX_N; i++)
        for(int j=0; j<MAX_SUM; j++)
            sumToMinNumber[i][j] = INF;
    
    sumToMinNumber[0][0] = 0;
    for(int i=1; i<=N; i++)
        for(int j=(i-1)*2; j<=(i-1)*7; j++) {
            if(sumToMinNumber[i-1][j] == INF) continue;
            for(int k=0; k<10; k++) {
                int nextJ = j + numberToCount[k];
                sumToMinNumber[i][nextJ] = min(sumToMinNumber[i][nextJ], sumToMinNumber[i-1][j] * 10 + k);
            }
        }
    
    int theSum = 0;
    for(int i=1; i<=N; i++)
        theSum += numberToCount[Number[i]];
    
    Number[N]++;
    
    for(int k=N; k>=1; k--) {
        Number[k-1] += Number[k] / 10;
        Number[k] %= 10;
        if(Number[k] == 0) continue;
        int nowSum = 0;
        for(int i=1; i<k; i++)
            nowSum += numberToCount[Number[i]];
        
        
        for(int i=Number[k]; i<=9; i++) {
            int findSum = theSum - nowSum - numberToCount[i];
            
            if(findSum < 0) continue;
            
            long long minNumber = sumToMinNumber[N-k][findSum];
            if(minNumber != INF) {
                for(int l=1; l<k; l++)
                    Answer[l] = Number[l];
                Answer[k] = i;
                for(int l=N; l>=k+1; l--) {
                    Answer[l] = minNumber % 10;
                    minNumber /= 10;
                }
                return;
            }
        }
        Number[k-1]++;
        Number[k] = 0;
    }
    for(int i=0; i<=9; i++) {
        int findSum = theSum - numberToCount[i];
        
        if(findSum < 0) continue;
        
        long long minNumber = sumToMinNumber[N-1][findSum];
        if(minNumber != INF) {
            Answer[1] = i;
            for(int l=N; l>=2; l--) {
                Answer[l] = minNumber % 10;
                minNumber /= 10;
            }
            return;
        }
    }
    
    printf("ERROR!\n");
}
//15
//8+5
int main() {
    Input();
    
    int theSum = 0, resultSum = 0;
    long long theN = 0;
    for(int i=1; i<=N; i++) {
        theN *= 10;
        theN += Number[i];
        theSum += numberToCount[Number[i]];
    }
    
    Process();
    
    long long resultN = 0;
    long long onePower = 1;
    for(int i=1; i<=N; i++) {
        resultN *= 10;
        resultN += Answer[i];
        onePower *= 10;
        resultSum += numberToCount[Answer[i]];
    }
    long long result = resultN - theN + onePower;
    result %= onePower;
    if(result == 0) result += onePower;
    
    printf("%lld", result);
    
    return 0;
}




