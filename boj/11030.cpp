//
//  main.cpp
//  11030
//
//  Created by KJBS2 on 2/10/16.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>

int A, B;

int CRT(int a, int b, int n, int m) {
    int mm = 0, nn = 0;
    for(long long s = 0; s != (1 % n); s+=m, mm++, s%=n);
    for(long long s = 0; s != (1 % m); s+=n, nn++, s%=m);
    
    return (int)((1ll*a*m*mm + 1ll*b*n*nn) % (1ll*n*m));
}
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int getMod(int a, int b, int x, int y) {
    int nowX = 1, nowY = 1;
    for(int i=0; i<x; i++, nowX *= 2);
    for(int i=0; i<y; i++, nowY *= 5);
    int nowM = nowX * nowY;

    if(b == 1) return a % nowM;
    
    int gcdA = gcd(a, 10);
    if(gcdA == 1) {
        
        int nx = y>0 ? x - 1 + 2 : x>0 ? x - 1 : 0;
        int ny = y>0 ? y - 1 : 0;
        int exponent = getMod(a, b-1, nx, ny);
        
        long long result = 1;
        for(int i=0; i<exponent; i++, result *= a, result %= nowM );
        
        return (int)result % nowM;
    }else if(gcdA == 2) {
        long long result2 = 1;
        if(b-1 >= 2) {
            if(a == 2 && b == 3) {
                int ex2 = 4;
                if(ex2 < x) for(int i=0; i<ex2; i++, result2 *= a);
                else result2 = 0;
            }else result2 = 0;
        }else if(b == 2) {
            int ex2 = a;
            if(ex2 < x) for(int i=0; i<ex2; i++, result2 *= a);
            else result2 = 0;
        }
        
        int nx = y>0 ? 2 : 0;
        int ny = y>0 ? y - 1 : 0;
        int exponent = getMod(a, b-1, nx, ny);
        long long result5 = 1;
        for(int i=0; i<exponent; i++, result5 *= a, result5 %= nowY );
        
        return CRT((int)result2 % nowX, (int)result5 % nowY, nowX, nowY);
    }else if(gcdA == 5) {
        long long result5 = 1;
        if(b-1 >= 2) {
            if(a == 2 && b == 3) {
                int ex2 = 4;
                if(ex2 < y) for(int i=0; i<ex2; i++, result5 *= a);
                else result5 = 0;
            }else result5 = 0;
        }else if(b == 2) {
            int ex2 = a;
            if(ex2 < y) for(int i=0; i<ex2; i++, result5 *= a);
            else result5 = 0;
        }
        
        int nx = x>0 ? x-1 : 0;
        int ny = 0;
        int exponent = getMod(a, b-1, nx, ny);
        long long result2 = 1;
        for(int i=0; i<exponent; i++, result2 *= a, result2 %= nowX );
        
        return CRT((int)result2 % nowX, (int)result5 % nowY, nowX, nowY);
    }
    return -1;
}

int main() {
    while(scanf("%d%d", &A, &B) != -1){
    if(B == 1) {
        printf("%d", A);
        continue;
    }
    if(A % 10 == 0) {
        printf("%08d", 0);
        continue;
    }
    if(A == 1) printf("1");
    else {
        int ans = getMod(A, B, 8, 8);
        
        if (A == 1 || B == 1 || (A == 2 && B <= 4) || (A <= 8 && B <= 2) )
            printf("%d", ans);
        else
            printf("%08d", ans);
    }}
}









