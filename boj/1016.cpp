//
//  main.cpp
//  1016
//
//  Created by KJBS2 on 2/7/16.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

const int MAX_Number = (int)1e6;

void getPrimes(vector<int> &primes) {
    vector<bool> notPrime(MAX_Number+1, false);
    
    for(int i=2; i<=MAX_Number; i++) {
        if(notPrime[i] == true) continue;
        
        primes.push_back(i);
        
        for(int j=i*2; j<=MAX_Number; j+=i)
            notPrime[j] = true;
    }
}

int main() {
    
    long long minNumber, maxNumber;
    scanf("%lld%lld", &minNumber, &maxNumber);
    
    vector<int> primes;
    getPrimes(primes);
    
    int length = (int)(maxNumber - minNumber);
    
    vector<bool> isCondition(length+1, true);
    for(int prime : primes) {
        long long primeSquare = 1ll * prime * prime;
        
        long long start = minNumber % primeSquare;
        if(start != 0) start = primeSquare - start;
        
        for(; start <= length; start += primeSquare)
            isCondition[start] = false;
    }
    
    int result = 0;
    for(long long i = minNumber; i <= maxNumber; i++)
        if(isCondition[i - minNumber])
            result++;
    
    printf("%d\n", result);
    
    return 0;
}