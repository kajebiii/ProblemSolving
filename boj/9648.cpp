#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int Days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
	int y, m, d;
	while(scanf("%d-%d-%d", &y, &m, &d) == 3)
	{
		int more = 11;
		for(int i=1584; i<=y-1; i+=4)
			if(i % 100 == 0 && i % 400 != 0) more++;
		if(y % 100 == 0 && y % 400 != 0)
			if(m > 2 || (m == 2 && d == 29)) more++;

		for(int i=1; i<=more; i++)
		{
			d++;
			if(y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) Days[2] = 29;
			else Days[2] = 28;

			if(d > Days[m])
			{
				d = 1;
				m++;
				if(m > 12) {y++; m = 1;}
			}
		}
		printf("%04d-%02d-%02d\n", y, m, d);
	}
	return 0;
}