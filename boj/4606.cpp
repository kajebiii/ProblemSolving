#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

bool chk[999];
int main()
{
	chk[' '] = chk['!'] = chk['$'] = chk['%'] = chk['('] = chk[')'] = chk['*'] = true;
	char data[555], *p;
	while(fgets(data, 555, stdin))
	{
		int N = strlen(data);
		if(data[0] == '#') break;
		for(int i=0; i<N; i++)
		{
			if(chk[data[i]])
				printf("%%%2x", data[i]);
			else
				printf("%c", data[i]);
		}
	}
	return 0;
}