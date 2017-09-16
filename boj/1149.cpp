
#include <stdio.h>
#include <algorithm>

using namespace std;

const int INF = 0x7fffffff;

int N;
int C[3];
int Dy[1111][3];

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
    {
        for(int j=0; j<3; j++)
            scanf("%d", &C[j]);
        for(int j=0; j<3; j++)
            Dy[i][j] = INF;
        if(i==1)
            for(int j=0; j<3; j++)
                Dy[i][j] = C[j];
        else
            for(int j=0; j<3; j++)
                for(int k=0; k<3; k++)
                    if(j != k)
                        Dy[i][j] = min(Dy[i-1][k] + C[j], Dy[i][j]);
    }
    
    printf("%d", min(min(Dy[N][0], Dy[N][1]), Dy[N][2]));
    
    return 0;
}