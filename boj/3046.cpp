#include <stdio.h>

int main()
{
    int r1, s;
    scanf("%d%d", &r1, &s);
    printf("%d", r1 + (s-r1) * 2);
    
    return 0;
}