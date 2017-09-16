#include <stdio.h>

int N;

int main()
{
    scanf("%d", &N);
    
    for(int i=0; i<N; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", a+b);
    }
    
    return 0;
}