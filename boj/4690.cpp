#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	for(int o=2; o<=100; o++)
		for(int a=2; a<=o; a++) for(int b=a; b<=o; b++) for(int c=b; c<=o; c++)
		{
			int v[4] = {o*o*o, a*a*a, b*b*b, c*c*c};
			if(v[0] < v[1] + v[2] + v[3]) break;
			if(v[0] == v[1] + v[2] + v[3])
			{
				printf("Cube = %d, Triple = (%d,%d,%d)\n", o, a, b, c);
			}
		}
	return 0;
}