#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 33;
int N; char Mp[MAX_N][MAX_N];
int Ch[4][2][2] = {{{1, 1}, {-1, -1}}, {{1, -1}, {-1, 1}}, {{0, 1}, {0, -1}}, {{1, 0}, {-1, 0}} };
int main()
{
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%s", Mp[i]+1);
	char who = '.';
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
	{
		if(Mp[i][j] == '.') continue;
		bool isSame = false;
		for(int k=0; k<4; k++)
		{
			bool now = true;
			for(int l=0; l<2; l++)
				now &= Mp[i][j] == Mp[i+Ch[k][l][0]][j+Ch[k][l][1]];
			isSame |= now;
			if(isSame) break;
		}
		if(isSame) {who = Mp[i][j]; break; }
	}
	if(who == '.') puts("ongoing");
	else printf("%c\n", who);
	return 0;
}