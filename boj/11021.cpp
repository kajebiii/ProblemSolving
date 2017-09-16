#include <stdio.h>


int main()
{
    int a, b;
    int N;
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
    {
        printf("Case #%d: ", i);
        scanf("%d%d", &a, &b);
        printf("%d\n", a+b);
    }
    
    return 0;
}