#include <stdio.h>

int N;

int main()
{
    scanf("%d", &N);
    int Sum = 1;
    for(int i=1; i<=N; i++)
    {
        int x;
        scanf("%d", &x);
        Sum += (x-1);
    }
    
    printf("%d", Sum);
    
    return 0;
}