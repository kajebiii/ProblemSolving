#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 32, MAX_L = 32;

int N, L, K;
int Dy[MAX_N][MAX_L];
bool Visit[MAX_N][MAX_L];
int getDy(int n, int l)
{
	int &val = Dy[n][l];
	if(l < 0) return val = 0;
	if(Visit[n][l]) return val;
	Visit[n][l] = true;
	if(n == 0) return val = 1;
	val = getDy(n-1, l-1) + getDy(n-1, l);
	return val;
}
void printAns(int n, int l, int k)
{
	if(n == 0) return;

	if(k > getDy(n-1, l))
	{
		printf("1");
		printAns(n-1, l-1, k-getDy(n-1, l));
	}
	else
	{
		printf("0");
		printAns(n-1, l, k);
	}
}
int main()
{
	long long K_;
	scanf("%d%d%lld", &N, &L, &K_);
	if(K_ == 2147483648ll)
	{
		for(int i=0; i<31; i++) printf("1");
		return 0;
	}
	K = K_;
	getDy(N, L);
	printAns(N, L, K);
	return 0;
}