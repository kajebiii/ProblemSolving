#include <stdio.h>
#include <algorithm>

using namespace std;

int Ch[9];
void printAns(int k)
{
	if(k == 0) return;
	printAns(k/9);
	printf("%d", Ch[k%9]);
}
void printAnsZ(int n, int k)
{
	if(k == 0) return;
	printAnsZ(n/9, k-1);
	printf("%d", n%9+1);
}
int main()
{
	int N, L; scanf("%d%d", &N, &L);
	for(int i=0; i<L; i++) Ch[i] = i;
	for(int i=L; i<9; i++) Ch[i] = i+1;
	if(L != 0) printAns(N);
	else
	{
		for(int k=1, now = 9; k<=9; k++, now *= 9)
		{
			if(N <= now)
			{
				printAnsZ(N-1, k);
				break;
			}
			else N -= now;
		}
	}
	return 0;
}