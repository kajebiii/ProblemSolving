#include<stdio.h>
#include<math.h>
#include<cassert>
#include<stdlib.h>
const int LIM = 1000000000;

typedef long long ll;

float _abs(float x){ return x < 0? -x : x; }
bool is_equal(double a, double b){ return _abs(a-b) < 1e-3; }

int main()
{
	int N, a;
	ll tot = 0;
	double x = 0;
	N = 100000;
	printf("%d\n", N);
	for(int i = 1; i <= N; i++){
		if(i <= N/2) a = 1000000000 + 99; else a = -1000000000 + 11; 
		if(i == N) a = -tot;
		printf("%d\n", a);
		tot += a;
		x += a / 100.0;
	}
	return 0;
}
