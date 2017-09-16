#include <stdio.h>

int N;
int D[15];

int main()
{
    D[0] = 1;
    D[1] = 1;
    D[2] = 2;
    D[3] = 4;
    
    for(int i = 4; i <= 13; i++)
        D[i] = D[i-1] + D[i-2] + D[i-3];
    
    int N;
    scanf("%d", &N);
    
    for(int i=1; i<=N; i++)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", D[x]);
    }
    
    return 0;
}