#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int C[9][9];

void add(int x, int y)
{
	C[x][y] = 1;
}

int main()
{
	add(1, 4);
	add(1, 5);
	add(3, 4);
	add(3, 5);
	add(4, 2);
	add(4, 3);
	add(5, 8);
	add(6, 2);
	add(6, 3);
	add(7, 8);
	add(8, 6);
	add(8, 7);

	char getIn[11111]; int t = 0;
	while(scanf("%s", getIn) == 1)
	{
		if(getIn[0] == '0') break;
		t++; printf("%d. ", t);
		int N = strlen(getIn);
		if(getIn[0] != '1' || getIn[N-1] != '2')
		{
			puts("NOT");
			continue;
		}
		bool isGood = true;
		for(int i=1; i<N; i++)
			if(C[getIn[i-1]-'0'][getIn[i]-'0'] == 0)
			{
				puts("NOT");
				isGood = false;
				break;
			}
		if(isGood) puts("VALID");
	}
	return 0;
}