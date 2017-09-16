#include <stdio.h>
#include <string.h>

int main()
{
	int tc; scanf("%d", &tc);
	while(tc--)
	{
		int Mod; scanf("%d ", &Mod);
		int ans = 0;
		while(1)
		{
			char c = getchar();
			if(c == EOF || c == '\n') break;
			ans += c - '0';
		}
		ans %= (Mod - 1);
		printf("%d\n", ans);
	}
	return 0;
}