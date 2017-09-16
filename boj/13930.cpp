#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int X, Y; scanf("%d%d", &X, &Y);
	int N; scanf("%d", &N);
	double calc = Y;
	int sum = 0;
	for(int i=1; i<=N; i++)
	{
		int l, u; double k;
		scanf("%d%d%lf", &l, &u, &k);
		sum += (u - l);
		calc += k * (u - l);
	}
	calc -= sum;
	printf("%.15lf\n", (double)X / calc);
	return 0;
}