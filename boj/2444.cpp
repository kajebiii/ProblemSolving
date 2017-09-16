#include <stdio.h>

int N;

int main()
{
    scanf("%d", &N);
    
    for(int i=1; i<=2*N-1; i+=2)
    {
        for(int j=1; j<=N-i/2-1; j++)
            printf(" ");
        for(int j=1; j<=i; j++)
            printf("*");
        printf("\n");
    }
    N--;
    for(int i=2*N-1; i>=1; i-=2)
    {
        for(int j=1; j<=N-i/2; j++)
            printf(" ");
        for(int j=1; j<=i; j++)
            printf("*");
        printf("\n");
    }
    
    return 0;
}