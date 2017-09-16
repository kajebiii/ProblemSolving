#include <stdio.h>

int gcd(int a, int b)
{
    if(a == 0) return b;
    return gcd(b%a, a);
}

int main()
{
    int N;
    scanf("%d", &N);
    
    for(int i=0; i<N; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", a*b/gcd(a,b));
    }
}