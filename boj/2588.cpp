#include <stdio.h>

int N, M;

int main()
{
    scanf("%d%d", &N, &M);
    
    printf("%d\n%d\n%d\n%d\n", N*(M%10), N*( (M/10) % 10), N*(M/100), N*M);
    
    return 0;
}