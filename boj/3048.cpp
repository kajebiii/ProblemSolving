#include <stdio.h>
#include <algorithm>

using namespace std;

struct ANT
{
	char k;
	int w;
	ANT() : k(' '), w(0) {}
	ANT(char k_, int w_) : k(k_), w(w_) {}
};
const int MAX_N = 1e6;
int A, B, N, T;
ANT Ant[MAX_N];
void getInput()
{
	scanf("%d%d", &A, &B); N = A + B;
	scanf(" ");
	
	for(int i=1; i<=A; i++)
	{
		char x;
		scanf("%c", &x);
		Ant[A+1-i] = ANT(x, 1);
	}
	scanf(" ");
	for(int i=1; i<=B; i++)
	{
		char x;
		scanf("%c", &x);
		Ant[A+i] = ANT(x, -1);
	}
	scanf("%d", &T);
}
int main()
{
	getInput();
	while(T--)
	{
		for(int i=1; i<N; i++)
		{
			if(Ant[i].w == 1 && Ant[i+1].w == -1)
			{
				swap(Ant[i], Ant[i+1]);
				i++;
			}
		}
	}
	for(int i=1; i<=N; i++) printf("%c", Ant[i].k);
	return 0;
}