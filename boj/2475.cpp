
#include <stdio.h>

int main()
{
    int r = 0;
    
    for(int i=0; i<5; i++)
    {
        int x;
        scanf("%d", &x);
        r += (x * x);
        r %= 10;
    }
    
    printf("%d", r);
    
    return 0;
}