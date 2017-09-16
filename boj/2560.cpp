#include <stdio.h>
#include <algorithm>
 
using namespace std;
 
const int MAX_N = 1e6 + 100;
 
int A, B, D, N;
int H[MAX_N], S[MAX_N];
int main()
{
    scanf("%d%d%d%d", &A, &B, &D, &N);
    H[0] = S[0] = 1;
    for(int i=1; i<=N; i++)
    {
        if(i >= A) H[i] = ((H[i] + S[i-A]) % 1000 + 1000) % 1000;
        if(i >= B) H[i] = ((H[i] - S[i-B]) % 1000 + 1000) % 1000;
        S[i] = ((S[i-1] + H[i]) % 1000 + 1000) % 1000;
    }
    int Ans = 0;
    for(int i=max(0, N-D+1); i<=N; i++)
        Ans = (Ans + H[i]) % 1000;
    printf("%d\n", Ans);
    return 0;
}