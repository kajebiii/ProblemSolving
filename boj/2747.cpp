#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
long long A[50];
int main()
{
    A[0] = 0;
    A[1] = 1;
    scanf("%d", &N);
    for(int i=2; i<=N; i++)
        A[i] = A[i-1] + A[i-2];
    
    printf("%lld\n", A[N]);
    
    return 0;
}