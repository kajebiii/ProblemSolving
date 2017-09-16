#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N, Nr[5];
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	scanf("%d ", &N);
	for(int t=1; t<=N; t++)
	{
		char getI[999], *p = getI;
		fgets(getI, 999, stdin);
		for(int i=0; i<5; i++)
		{
			int x = -1, cnts = 0;
			if(sscanf(p, " %d%n", &x, &cnts) == 1)
			{
				Nr[i] = x;
				p += cnts;
			}
			else
			{
				sscanf(p, " ?%n", &cnts);
				Nr[i] = -1;
				p += cnts;
			}
		}
		int a = Nr[0], x = Nr[1], y = Nr[2], z = Nr[3], b = Nr[4];
		int x0 = Nr[1], x1 = Nr[1], y0 = Nr[2], y1 = Nr[2];
		if(Nr[1] == -1) x0 = 0, x1 = 100;
		if(Nr[2] == -1) y0 = 0, y1 = 100;
		if(a == -1 && z == -1) z = 0;
		bool find = false;
		for(int cx = x0; cx <= x1; cx++) for(int cy = y0; cy <= y1; cy++)
		{
			int ca = a, cz = z, cb = b;
			if(ca == -1) ca = (cx + cy + cz);
			if(cz == -1) cz = (ca - cy - cx);
			if(cb == -1) cb = (cx * 3 + cy);
			if(cb == cx * 3 + cy && ca == cx + cy + cz && cz >= 0 && ca <= 100)
			{
				printf("%d %d %d %d %d\n", ca, cx, cy, cz, cb);
				find = true;
			}
		}
//		if(find == false) {for(int i=0; i<5; i++) printf("%d ", Nr[i]); puts("");}
	}
	return 0;
}