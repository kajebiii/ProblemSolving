#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e6 + 100;

int N;
double Dy[MAX_N];

int main()
{
	scanf("%d", &N);
	Dy[0] = 1;
	double ans = 0;
	for(int i=0; i<N; i++)
	{
		for(int j=1; j<=6; j++) Dy[i+j] += Dy[i] / 6;
		ans += Dy[i];
	}
	printf("%.20lf\n", ans);
	return 0;
}