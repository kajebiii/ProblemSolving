//
//  main.cpp
//  1022
//
//  Created by KJBS2 on 2/9/16.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int maxAbs(int value0, int value1) {
    if(abs(value0) == abs(value1)) return min(value0, value1);
    return max(abs(value0), abs(value1)) == abs(value0) ? value0 : value1;
}


int getNumber(int x, int y) {
    x = -x;
    
    int number = 1;
    
    int maxDiff = max(abs(x), abs(y));
    
    int stepCount = maxDiff * 2 - (x + y > 0);
    
    number += stepCount * (stepCount + 1);
    
    int maxAbsXY = maxAbs(x, y);
    number += abs(y - maxAbsXY) - abs(x - maxAbsXY);
    
    return number;
}

int getDigit(int number) {
    int digit = 1;
    for(; number>=10; number/=10, digit++);
    
    return digit;
}

int saveDigit[20];
void printDigit(int number, int digit) {
    for(int i=1; i<=digit; i++, number /= 10)
        saveDigit[i] = number % 10;
    
    bool flag = true;
    for(int i=digit; i>=1; i--) {
        if(saveDigit[i] == 0 && flag) printf(" ");
        else {
            printf("%d", saveDigit[i]);
            flag = false;
        }
    }
}

int main() {
    int r1, c1, r2, c2;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    
    int maxDigit = 0;
    for(int i=r1; i<=r2; i++)
        for(int j=c1; j<=c2; j++)
            maxDigit = max(maxDigit, getDigit(getNumber(i, j)) );
    
    for(int i=r1; i<=r2; i++, printf("\n"))
        for(int j=c1; j<=c2; j++, printf(" "))
            printDigit(getNumber(i, j), maxDigit);
    
    
    return 0;
}