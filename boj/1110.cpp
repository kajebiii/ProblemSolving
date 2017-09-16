
#include <stdio.h>


int get(int x)
{
    return ((x%10)*10 + ((x%10) + (x/10))%10);
}

int main()
{
    int x, A;
    scanf("%d", &x);
    
    int cnt = 0;
    A = x;
    do
    {
        x = get(x);
        cnt++;
    }while(A != x);
    
    printf("%d\n", cnt);
    
    return 0;
}