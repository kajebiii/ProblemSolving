#include <stdio.h>
#include <algorithm>
 
using namespace std;
 
const int MAX_N = 1e2 + 10, MAX_V = 1e5, MOD = 1e7 + 3;
 
int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}
int N, Nr[MAX_N], Dy[MAX_N][MAX_V+1];
int main()
{
    scanf("%d", &N); for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
    for(int i=1; i<=N; i++)
    {
        Dy[i][Nr[i]]++;
        for(int j=1; j<=MAX_V; j++) 
        {
            Dy[i][j] += Dy[i-1][j];
            Dy[i][j] %= MOD;
        }
 
        for(int j=1; j<=MAX_V; j++)
            if(Dy[i-1][j] != 0)
            {
                int g = gcd(j, Nr[i]);
                Dy[i][g] += Dy[i-1][j];
                Dy[i][g] %= MOD;
            }
    }
    printf("%d", Dy[N][1]);
    return 0;
}