#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e2 + 10;

int gcd(int x, int y){return y==0?x:gcd(y, x%y);}

int N, Nr[MAX_N];
int main()
{
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
	sort(Nr+1, Nr+N+1);
	for(int i=2; i<=N; i++) Nr[i] -= Nr[1];
	int val = Nr[2];
	for(int i=3; i<=N; i++) val = gcd(val, Nr[i]);
	vector<int> Ans;
	for(int i=1; i*i<=val; i++)
	{
		if(val % i == 0)
		{
			Ans.push_back(i);
			if(val != i*i) Ans.push_back(val / i);
		}
	}
	sort(Ans.begin(), Ans.end());
	for(int x : Ans) if(x != 1) printf("%d ", x);
	return 0;
}