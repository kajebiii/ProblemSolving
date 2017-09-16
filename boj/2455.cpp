#include <stdio.h>
#include <algorithm>

using namespace std;

int N = 4;
int Sum = 0;
int Ans = 0;

int main()
{
    for(int i=1; i<=N; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        Sum += y;
        Sum -= x;
        Ans = max(Ans, Sum);
    }
    
    printf("%d", Ans);
    
    return 0;
}