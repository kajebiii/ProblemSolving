#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main()
{
	double A[6];
	for(int i=0; i<6; i++) scanf("%lf", &A[i]);
	double minV = 5000;
	for(int i=0; i<3; i++) minV = min(A[i] / A[i+3], minV);
	for(int i=0; i<3; i++) printf("%lf ", A[i] - A[i+3] * minV);
	return 0;
}