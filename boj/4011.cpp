#include <stdio.h>
int n, m, k;
int sum[1519][1519];
int sumfast[1519][1519];
int val[1519][1519];
int add[1519][1519];
int nadd[1519], madd[1519];
int leftup[1519][1519];
int rightup[1519][1519];
int leftdown[1519][1519];
int rightdown[1519][1519];
int nmid[1519][1519];
int mmid[1519][1519];
int ans, now;
inline int pmax(int x, int y){
    if(x>y) return x;
    else return y;
}

void setting(){
    int i, j;
    //leftup;
    for(i=k; i<=n; i++) {
        for(j=k; j<=m; j++) {
            nadd[i]=pmax(nadd[i], add[i][j]);
            madd[j]=pmax(madd[j], add[i][j]);

            leftup[i][j]=add[i][j];
            if(i>k) leftup[i][j]=pmax(leftup[i][j], leftup[i-1][j]);
            if(j>k) leftup[i][j]=pmax(leftup[i][j], leftup[i][j-1]);
        }
    }
    //rightup;
    for(i=k; i<=n; i++) {
        for(j=m-k+1; j>=1; j--) {
            rightup[i][j]=add[i][j+k-1];
            if(i>k) rightup[i][j]=pmax(rightup[i][j], rightup[i-1][j]);
            if(j<m-k+1) rightup[i][j]=pmax(rightup[i][j], rightup[i][j+1]);
        }
    }
    //leftdown;
    for(i=n-k+1; i>=1; i--) {
        for(j=k; j<=m; j++) {
            leftdown[i][j]=add[i+k-1][j];
            if(i>k) leftdown[i][j]=pmax(leftdown[i][j], leftdown[i-1][j]);
            if(j>k) leftdown[i][j]=pmax(leftdown[i][j], leftdown[i][j-1]);
        }
    }
    //rightdown;
    for(i=n-k+1; i>=1; i--) {
        for(j=m-k+1; j>=1; j--) {
            rightdown[i][j]=add[i+k-1][j+k-1];
            if(i>k) rightdown[i][j]=pmax(rightdown[i][j], rightdown[i-1][j]);
            if(j<m-k+1) rightdown[i][j]=pmax(rightdown[i][j], rightdown[i][j+1]);
        }
    }
    //nmid;
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            if(i+k-1<=j) {
                nmid[i][j]=nadd[j];
                if(j>i+k-1) nmid[i][j]=pmax(nmid[i][j], nmid[i][j-1]);
            }
        }
    }
    //mmid;
    for(i=1; i<=m; i++) {
        for(j=1; j<=m; j++) {
            if(i+k-1<=j) {
                mmid[i][j]=madd[j];
                if(j>i+k-1) mmid[i][j]=pmax(mmid[i][j], mmid[i][j-1]);
            }
        }
    }
}

void finding(){
    int i, j;
    for(i=1; i<=n; i++) {
        for(j=1; j<=m; j++) {
            if(nmid[1][i] && nmid[i+1][j] && nmid[j+1][n]) {
                now=nmid[1][i]+nmid[i+1][j]+nmid[j+1][n];
                if(ans<now) ans=now;
            }
        }
    }
    for(i=1; i<=m; i++) {
        for(j=1; j<=m; j++) {
            if(mmid[1][i] && mmid[i+1][j] && mmid[j+1][m]) {
                now=mmid[1][i]+mmid[i+1][j]+mmid[j+1][m];
                if(ans<now) ans=now;
            }
        }
    }
    for(i=1; i<=n; i++) {
        for(j=1; j<=m; j++) {
            if(leftup[i][j] && rightup[i][j+1] && nmid[i+1][n]) {
                now=leftup[i][j]+rightup[i][j+1]+nmid[i+1][n];
                if(ans<now) ans=now;
            }
            if(leftdown[i][j] && rightdown[i][j+1] && nmid[1][i-1]) {
                now=leftdown[i][j]+rightdown[i][j+1]+nmid[1][i-1];
                if(ans<now) ans=now;
            }
            if(leftup[i][j] && leftdown[i+1][j] && mmid[j+1][m]) {
                now=leftup[i][j]+leftdown[i+1][j]+mmid[j+1][m];
                if(ans<now) ans=now;
            }
            if(rightup[i][j] && rightdown[i+1][j] && mmid[1][j-1]) {
                now=rightup[i][j]+rightdown[i+1][j]+mmid[1][j-1];
                if(ans<now) ans=now;
            }
        }
    }
}

int main() {
    int i, j, l, o;
    scanf("%d %d %d", &n, &m, &k);
    for(i=1; i<=n; i++) for(j=1; j<=m; j++) {
        scanf("%d", &val[i][j]);
        sum[i][j]=sum[i][j-1]+val[i][j];
        sumfast[i][j]=sumfast[i-1][j]+sum[i][j];
        if(i<k && j<k) add[i][j]=2100000000;
    }
    for(i=k; i<=n; i++) {
        for(j=k; j<=m; j++) {
            add[i][j]=sumfast[i][j]-sumfast[i-k][j]-sumfast[i][j-k]+sumfast[i-k][j-k];
        }
    }
    setting();

    finding();

    printf("%d",ans);

    return 0;
}