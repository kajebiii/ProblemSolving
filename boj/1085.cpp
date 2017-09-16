#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main()
{
    int x, y, a, b;
    
    scanf("%d%d%d%d", &x, &y, &a, &b);
    printf("%d", min(min(a-x, x), min(b-y, y)));
    
    return 0;
}