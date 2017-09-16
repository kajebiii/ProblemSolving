#include <stdio.h>

int A, B, C;

int main()
{
    scanf("%d%d%d", &A, &B, &C);
    
    B += C;
    A += B / 60;
    B %= 60;
    A %= 24;
    
    printf("%d %d\n", A, B);
    
    return 0;
}