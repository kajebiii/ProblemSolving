#include <stdio.h>
#include <algorithm>

using namespace std;

int ggcd(int a, int b) {return b==0?a:ggcd(b, a%b); }

int main()
{
	int A, B, C;
	while(scanf("%d%d%d", &A, &B, &C) == 3)
	{
		int a = B * A, b = C - B;
		int g = ggcd(a, b);
		printf("%d/%d\n", a/g, b/g);
	}
}