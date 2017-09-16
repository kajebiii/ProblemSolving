#include <stdio.h>

int gcd(int a, int b)
{
    if(a == 0) return b;
    return gcd(b%a, a);
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n%d\n", gcd(a, b), a*b/gcd(a,b));
    
    return 0;
}