#include <stdio.h>

int N;

int main()
{
    scanf("%d", &N);
    
    if( (N % 4 == 0 && N % 100 != 0) || N % 400 == 0)
        printf("1\n");
    else
        printf("0\n");
    
    return 0;
}