#include <stdio.h>
#include <queue>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    
    queue< pair<int, int> > Q;
    Q.push(make_pair(N, 0));
    
    while(!Q.empty())
    {
        int now = Q.front().first;
        int how = Q.front().second;
        Q.pop();
        
        if(now == 1)
        {
            printf("%d\n", how);
            return 0;
        }
        if(now % 3 == 0)
            Q.push(make_pair(now/3, how+1));
        if(now % 2 == 0)
            Q.push(make_pair(now/2, how+1));
        Q.push(make_pair(now-1, how+1));
    }
    
    return 0;
}