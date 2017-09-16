#include <stdio.h>


int main()
{
    int a, b;
    int N;
    scanf("%d", &N);
    while(scanf("%1d,%1d", &a, &b) != EOF)
    {
        if(a == 0 && b == 0) break;
        printf("%d\n", a+b);
    }
    
    return 0;
}