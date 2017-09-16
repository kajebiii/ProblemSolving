#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int MAX_NR = 1e7;

bool notP[MAX_NR+1];

int main()
{
	[&]() //Eratosthenes
	{
		notP[0] = notP[1] = true;
		for(int i=2; i<=MAX_NR; i++) if(notP[i] == false)
			for(int j=i+i; j<=MAX_NR; j+=i) notP[j] = true;
	}();
	int N, A; scanf("%d%d", &N, &A);
	N += A * 1000000;
	puts(notP[N]|notP[N-A*1000000]?"No":"Yes");
	return 0;
}