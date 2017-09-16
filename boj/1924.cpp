//
//  main.cpp
//  1924
//
//  Created by KJBS2 on 2016. 1. 17..
//  Copyright (c) 2016년 KJBS2. All rights reserved.
//

#include <stdio.h>

int Days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int X, Y;
char StringDay[7][9] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    scanf("%d%d", &X, &Y);
    
    int day = Y - 1;
    for(int i=1; i<X; i++)
        day += Days[i];
    
    printf("%s\n", StringDay[day % 7]);
    
    return 0;
}