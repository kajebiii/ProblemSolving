#include<stdio.h>
#include<queue>
using namespace std;
int w[501][501], a[501], b[501], n, v[501], mv[501], mx[501], s[501], t[501], lx[501], ly[501];
int main()
{
	int ans=0;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)for(int j=1; j<=n; j++)scanf("%d", &w[i][j]);
	for(int f=0; f<n;)for(int k=1; k<=n && f<n; k++)if(a[k] == 0) {
		for(int i=1; i<=n; i++) s[i]=t[i]=0, mv[i]=2147483647;
		int m=-1;
		for(int x=k;x;t[m]=1, x=b[m]) {
			s[x] = 1;
			m = -1;
			for(int j=1; j<=n; j++) if(w[x][j]-lx[x]-ly[j] < mv[j]) {
				mv[j] = w[x][j]-lx[x]-ly[j];
				mx[j] = x;
			}
			for(int j=1; j<=n; j++)if(t[j] == 0 && (m==-1 || mv[j] < mv[m])) m = j;
			if(mv[m] != 0) {
				int d = mv[m];
				for(int i=1; i<=n; i++) {
					if(s[i]) lx[i] += d;
					if(t[i]) ly[i] -= d;
					if(!t[i]) mv[i] -= d;
				}
			}
		}
		for(int t=m, x; x=mx[t], m=t;b[a[x] = m] = x) t = a[x];
		f++;
	}
	for(int i=1; i<=n; i++) ans += lx[i]+ly[i];
	printf("%d", ans);
	return 0;
}