#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int gcd(int a, int b) {return b?gcd(b, a%b):a; }

int main()
{
	scanf("%d", &N);
	if(N % 2 == 0 || N % 5 == 0) {puts("-1"); return 0;}
	for(int p=1, now = 1 % N; ; p++, now = (now*10 + 1) % N)
	{
		if(now != 0) continue;
		printf("%d\n", p);
		return 0;
	}
	return 0;
}