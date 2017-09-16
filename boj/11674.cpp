#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string S; cin >> S;
	int N = S.size();

	int x = 0, y = 0;
	for(int i=0, p=1; i<N; i++, p*=2)
	{
		int now = S[i] - '0';
		x *= 2; y *= 2;
		x += (now % 2);
		y += (now / 2);
	}
	printf("%d %d %d\n", N, x, y);
	return 0;
}