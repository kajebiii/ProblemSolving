#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int N; double P, S, V;

double getV(double c)
{
	return N * pow(log(N) / log(2), c * sqrt(2)) / P / 1e9 + S * (1 + 1 / c) / V;
}
int main()
{
	scanf("%d%lf%lf%lf", &N, &P, &S, &V);
	int cnt = 0; double ans = -1;
	for(double l = 0, r = log(1e12 * 1e9 * P / N) / log(log(N) / log(2)); cnt < 200; cnt++)
	{
		double m[2] = {(2*l + r) / 3, (l + 2*r) / 3};
		if(getV(m[0]) < getV(m[1]))
			r = m[1];
		else
			l = m[0];
		cnt++;
		ans = l;
	}
	printf("%.15lf %.15lf\n", getV(ans), ans);
	return 0;
}