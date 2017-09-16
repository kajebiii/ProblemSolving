#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string.h>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
#define mp make_pair
#define fi first
#define se second
#define pb push_back

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, 1), mp(1, 0), mp(0, -1)};

ll A, B; int K;
double C[3][5];
void circle(int v)
{
	double ratio = (C[v][2] - C[v][0] * 2) / C[v][2];
	C[v][0] = C[v][0] * ratio;
	C[v][2] = C[v][2] * ratio;
	return;
}
int main()
{
	int T; cin >> T;
	while(T--)
	{
		scanf("%lld%lld%d", &A, &B, &K);
		double fR = (double)(A*B) / (A+B+(double)(sqrt(A*A+B*B)));
		if(K == 1) {printf("%.10lf\n", fR*fR*M_PI); continue;}
		double a = A, b = B, c = (double)(sqrt(A*A+B*B));
		double l[3] = {a, b, c}, sum = a+b+c;
		for(int i=0; i<3; i++)
		{
			C[i][0] = fR;
			double lt = sum/2 - l[i];
			double ll = sqrt(lt * lt + fR * fR);
			double ratio = (ll+fR)/ll;
			C[i][1] = lt * ratio;
			C[i][2] = ll * ratio;
			circle(i);
		}
		for(int i=2; i<=K; i++)
		{
			double maxR = -1; int maxIx = -1;
			for(int j=0; j<3; j++) if(C[j][0] > maxR) {maxR = C[j][0]; maxIx = j;}
			circle(maxIx);
			if(i == K) printf("%.10lf\n", maxR*maxR*M_PI);
		}
	}
	return 0;
}
