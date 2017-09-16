#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

char S[1111];
map<string, bool> Mp;

int main()
{
//'i', 'pa', 'te', 'ni', 'niti', 'a', 'ali', 'nego', 'no', 'ili'.
	Mp["i"] = Mp["pa"] = Mp["te"] = Mp["ni"] = Mp["niti"] = Mp["a"] = Mp["ali"] = Mp["nego"] = Mp["no"] = Mp["ili"] = true;
	fgets(S, 1111, stdin);
	char *p = S;
	char now[1111]; int move, cnt = 0;
	while(sscanf(p, "%s%n", now, &move) == 1)
	{
		p += move;
		cnt++;
		if(cnt == 1 || Mp[now] == false) printf("%c", now[0]-'a'+'A');
	}
	return 0;
}