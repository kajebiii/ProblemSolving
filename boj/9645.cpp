#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

const int MAX_N = 1e2 + 10;
const double EPS = 1e-9;

int N, M, Nr[MAX_N], Sum;
double Dy[2000];
map<char, int> Mp;
void init()
{
	char getin[400];
	scanf(" ");
	fgets(getin, 400, stdin);
	char *p = getin;
	for(int i=1; i<=N; i++)
	{
		int x; char y; int k;
		if(sscanf(p, "%d%n", &x, &k) == 1)
			Nr[i] = x;
		else if(sscanf(p, " %c%n", &y, &k) == 1)
			Nr[i] = Mp[y];
		p += k;
	}
	for(int i=1; i<2000; i++) Dy[i] = 0;
	Sum = M; for(int i=1; i<N; i++) {Dy[Sum] = 1, Sum += Nr[i];} Dy[Sum] = 1;
}

int Ch[12] = {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1};
int main()
{
	Mp['J'] = Mp['Q'] = Mp['K'] = 10; Mp['A'] = 11;
	while(scanf("%d%d", &N, &M) == 2)
	{
		init();
		for(int i=Sum-1; i>=1; i--)
			if(abs(Dy[i]) < EPS)
				for(int j=2; j<=11; j++)
					Dy[i] += Dy[i+j] * Ch[j] / 13;
		double ans = 0;
		for(int j=1; j<=10; j++) ans += Dy[j];
		ans /= 10;
		printf("%.15lf\n", ans);
	}
	return 0;
}