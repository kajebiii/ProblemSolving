#include <stdio.h>
#include <algorithm>

using namespace std;

const int MOD = 1e6;

long long N;
int Mul(int x, int y)
{
    int result = 0;
    while(y)
    {
        if(y%2 == 1)
        {
            result += x;
            result %= MOD;
        }
        x *= 2;
        x %= MOD;
        y /= 2;
    }
    
    return result;
}

struct METRIX
{
    int A[2][2];
    METRIX()
    {
        A[0][0] = A[0][1] = A[1][0] = A[1][1] = 0;
    }
};
METRIX Mul(METRIX &X, METRIX &Y)
{
    METRIX result;
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            for(int k=0; k<2; k++)
            {
                result.A[i][j] += Mul(X.A[i][k], Y.A[k][j]);
                result.A[i][j] %= MOD;
            }
    return result;
}

int main()
{
    scanf("%lld", &N);
    
    METRIX Ans, Power;
    Ans.A[0][0] = Ans.A[1][1] = 1;
    Power.A[0][0] = Power.A[0][1] = Power.A[1][0] = 1;
    while(N)
    {
        if(N%2 == 1)
            Ans = Mul(Ans, Power);
        Power = Mul(Power, Power);
        N /= 2;
    }
    
    printf("%d", Ans.A[1][0]);
    
    return 0;
}