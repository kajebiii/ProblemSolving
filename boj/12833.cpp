#include <stdio.h>

int main()
{
    long long A, B, C;
    scanf("%lld%lld%lld", &A, &B, &C);
    if(C%2 == 1)
        printf("%lld", A ^ B);
    else
        printf("%lld", A);
    return 0;
}