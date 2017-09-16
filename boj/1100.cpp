#include <stdio.h>

int N = 8;

int main()
{
    char A[9];
    int cnt = 0;
    for(int i=0; i<N; i++)
    {
        scanf("%s", A);
        for(int j=0; j<N; j++)
            if( (i+j)%2 == 0 && A[j] == 'F')
                cnt++;
    }
    
    printf("%d", cnt);
    
    return 0;
}