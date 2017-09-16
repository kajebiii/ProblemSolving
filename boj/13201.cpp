#include <stdio.h>
#include <math.h>
#include <string.h>
#include <queue>
#include <memory.h>
#define maxf(a,b) ((a)>(b)?(a):(b))
using namespace std;
char name[111][5];
double dp1[111], dp2[111], p[111][111];
int way[111][111], sum[111];
int N, K;

int main() {
    int T; scanf ("%d",&T);
    while(T--) {
        scanf ("%d%d",&N,&K);
        int start = 0;
        for (int i=1;i<=N;i++) {
            scanf ("\n%s",name[i]);
            if (strcmp(name[i], "ICN")==0) start = i;
            sum[i] = 0;
        }
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=N;j++) {
                scanf ("%d",&way[i][j]);
                sum[i] += way[i][j];
            }
            if(sum[i] == 0)
            {
                for(int j=1; j<=N; j++) p[i][j] = 0;
                continue;
            }
            for (int j=1;j<=N;j++) p[i][j]=(double)way[i][j]/sum[i];
        }
        for (int i=1;i<=N;i++) dp1[i] = 0;
        dp1[start] = 1;
        for (int i=1;i<=K;i++) {
            double total = 0;
            for (int j=1;j<=N;j++) {
                dp2[j] = 0;
                for (int k=1;k<=N;k++) dp2[j] = maxf(dp2[j], dp1[k]*p[k][j]);
                total += dp2[j];
            }
            for (int j=1;j<=N;j++) {
                dp1[j] = dp2[j] / total;
            }
        }
        double ans = 0; int pos = 0;
        for (int i=1;i<=N;i++) {
            if (ans < dp1[i]) {
                ans = dp1[i];
                pos = i;
            }
        }
        printf ("%s\n",name[pos]);
    }
    return 0;
}