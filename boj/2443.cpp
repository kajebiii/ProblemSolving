
#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    
    for(int i=2*N-1; i>=1; i-=2)
    {
        for(int j=0; j<N - i/2 - 1; j++)
            printf(" ");
        for(int j=0; j<i; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}