#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

int N, A, B;
string Ans; int Sum = 0, maxV = -1;

int main()
{
	scanf("%d", &N);
	while(N--)
	{
		string now; cin >> now;
		scanf("%d%d", &A, &B);
		B -= 2;
		Sum += (B / (A-2));
		if((B/(A-2)) > maxV)
		{
			maxV = (B/(A-2));
			Ans = now;
		}
	}
	printf("%d\n", Sum);
	cout << Ans;
	return 0;
}