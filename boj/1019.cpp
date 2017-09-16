//
//  main.cpp
//  1019
//
//  Created by KJBS2 on 2/7/16.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>

int countArray[10];

void countFunction(int N, int cipher) {
    if(cipher == 0) return;
    
    int theN = N;
    
    int oneCipher = 1;
    for(int i=1; i<cipher; i++) {
        oneCipher *= 10;
        theN /= 10;
    }
    
    for(int i=0; i<theN; i++)
        countArray[i] += oneCipher;
    countArray[theN] += (N - theN * oneCipher + 1);
    
    countFunction(N - theN * oneCipher, cipher - 1);
    
    cipher--;
    oneCipher /= 10;
    for(int i=0; i<10; i++)
        countArray[i] += cipher * oneCipher * theN;
}

int main() {
    int N;
    scanf("%d", &N);

    int theN = N;
    
    int cipher = 1;
    for(; theN >= 10; theN/=10, cipher++);
    
    countFunction(N, cipher);
    
    int oneCipher = 1;
    for(int i=1; i<cipher; i++)
        oneCipher *= 10;
    for(int i=1; i<=cipher; i++) {
        countArray[0] -= oneCipher;
        oneCipher /= 10;
    }
    
    for(int i=0; i<10; i++)
        printf("%d ", countArray[i]);
    
    return 0;
}






