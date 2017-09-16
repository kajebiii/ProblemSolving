#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e6 + 100;

int N, Nr[2][MAX_N];

bool isCan(int w)
{
	bool isGood = true;
	for(int k=0; k<2; k++)
	{
		int cnt = 0, now = -1;
		for(int i=0; i<N; i++)
			if(Nr[k][i] > w)
			{
				if(cnt == 0) now = Nr[k][i];
				else if(now != Nr[k][i]) isGood = false;
				cnt = 1 - cnt;
			}
		if(cnt == 1) isGood = false;
	}
	return isGood;
}

int main()
{
	scanf("%d", &N);
	for(int k=0; k<2; k++) for(int i=0; i<N; i++) scanf("%d", &Nr[k][i]);
	int result = -1;
	for(int l=0, r=1e9; l<=r; )
	{
		int m = (l + r) / 2;
		bool val = isCan(m);
		if(val) result = m;
		if(val)
			r = m - 1;
		else
			l = m + 1;
	}
	printf("%d\n", result);
	return 0;
}