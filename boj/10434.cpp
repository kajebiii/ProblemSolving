#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e4;

bool notP[MAX_N + 100];
bool Happy[MAX_N + 100];
int Visit[MAX_N + 100];

int calc(int n)
{
	int val = 0;
	do{val += (n%10) * (n%10); }while(n/=10);
	return val;
}
bool isHappy(int n)
{
	if(Visit[n] == 1) return Happy[n];
	if(Visit[n] == 2)
	{
		Visit[n] = 1;
		return Happy[n] = false;
	}
	Visit[n] = 2;
	bool val = isHappy(calc(n));
	Visit[n] = 1;
	return Happy[n] = val;
}

int main()
{
	notP[1] = true; for(int i=2; i<=MAX_N; i++) if(notP[i] == false) for(int j=i*2; j<=MAX_N; j+=i) notP[j] = true;
	int Q; scanf("%d", &Q);
	Visit[1] = Happy[1] = true;
	for(int _=0; _<Q; _++)
	{
		int t, n; scanf("%d%d", &t, &n);
		printf("%d %d ", t, n);
		if(notP[n] == false && isHappy(n) == true) puts("YES"); else puts("NO");
	}
	return 0;
}