#include <stdio.h>

int A, B, C;

int main()
{
    int ix = -1, max = -1;
    
    for(int i=1; i<=9; i++)
    {
        int x;
        scanf("%d", &x);
        if(max < x)
        {
            max = x;
            ix = i;
        }
    }
    
    printf("%d\n%d\n", max, ix);
    
    return 0;
}