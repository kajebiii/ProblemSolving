#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_D = 360;

vector<bool> Can = vector<bool>(MAX_D, false);

int main()
{
	int N, K; scanf("%d%d", &N, &K);
	Can[0] = true;
	for(int i=0; i<N; i++)
	{
		vector<bool> next = vector<bool>(MAX_D, false);
		int x; scanf("%d", &x);
		for(int p=0; p<MAX_D; p++) if(Can[p] == true)
			for(int k=0; k<MAX_D; k++)
				next[(k*x+p)%MAX_D] = true;
		Can.swap(next);
	}
	for(int i=0; i<K; i++)
	{
		int x; scanf("%d", &x);
		bool isCan = false;
		for(int p=0; p<MAX_D; p++)
			if(Can[p] && Can[(p+x)%MAX_D])
				isCan = true;
		puts(isCan?"YES":"NO");
	}
	return 0;
}