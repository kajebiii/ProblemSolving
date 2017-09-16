#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAX_N = 2e5 + 100;

int N; int P[MAX_N * 3 / 4]; unsigned short PP[MAX_N / 4];
int base;
char Nr[MAX_N];
inline int intP(int v) {
	if(v < base) return PP[v];
	return P[v - base];
}

void getP()
{
	base = N / 4;
	int r = 0, p = 0;
	Nr[0] = '.';
	Nr[N+1] = ',';
	for(int i=1; i<=N; i++)
	{
		int val = (i <= r)?min(intP(p - (i-p)), r-i):0;
		if(i < base) PP[i] = val; else P[i-base] = val;
		while(Nr[i-intP(i)-1] == Nr[i+intP(i)+1]) {
			if(i < base) PP[i]++;
			else P[i-base]++;
		}
		if(r < i+intP(i)) r = i+intP(i), p = i;
	}
}

int main() {
	scanf("%s", Nr+1); N = strlen(Nr+1);
	for(int i=N; i>=1; i--) Nr[i*2-1] = Nr[i];
	for(int i=N-1; i>=1; i--) Nr[i*2] = '*';
	N = 2*N - 1;
	getP();
	int ans = 1;
	for(int i=1; i<=N; i++)
	{
		if(i % 2 == 1) ans = max(ans, 1 + intP(i)/2 * 2);
		else ans = max(ans, (intP(i)+1)/2 * 2);
	}
	printf("%d\n", ans);
	return 0;
}