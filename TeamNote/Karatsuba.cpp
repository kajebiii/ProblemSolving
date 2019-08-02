#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f3f3f3f;
const ll LINF = 1ll * INF * INF;

typedef vector<long long> VI;

const int MAX_N = 3e5 + 100, MOD = 1e9, MOD_K = 9;
char forInput[2][MAX_N];
VI A[2];

void Print(VI &result) {
    int n = SZ(result);
    bool isFirst = true;
    for(int i=n-1; i>=0; i--) {
        if(isFirst && result[i] != 0) {
            printf("%d", result[i]), isFirst = false;
        }else if(!isFirst) printf("%09d", result[i]);
    }
    if(isFirst) printf("0");
    puts("");
    //for(int i=n-1; i>=0; i--) printf("%09d ", result[i]); puts("");
}

void clear(VI &R) {
    for(int i=0; i+1<SZ(R); i++) {
        R[i+1] += R[i]/MOD;
        R[i] %= MOD;
        if(R[i] < 0) R[i] += MOD, R[i+1]--;
    }
}
VI MULTI(VI X, VI Y) {
    int N = max((int)X.size(), (int)Y.size()), N2 = N / 2;
    VI R(N * 2, 0);

    if (N > 100) {
        VI X2(X.begin() + N2, X.end());
        VI Y2(Y.begin() + N2, Y.end());
        X.resize(N2); Y.resize(N2);

        VI A = MULTI(X, Y);
        VI B = MULTI(X2, Y2);
        for (int i = 0; i < N2; i++) X2[i] += X[i], Y2[i] += Y[i];
        X2.push_back(0ll); Y2.push_back(0ll);
        clear(X2); clear(Y2);
        VI C = MULTI(X2, Y2);

        for (int i = 0; i < A.size(); i++) R[i] += A[i], C[i] -= A[i];
        for (int i = 0; i < B.size(); i++) R[i + N2 * 2] += B[i], C[i] -= B[i];
        for (int i = 0; i < C.size(); i++) R[i + N2] += C[i];
    }
    else {
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            R[i + j] += X[i] * Y[j];
            R[i + j + 1] += R[i + j] / MOD;
            R[i + j] %= MOD;
        }
    }
    clear(R);
    return R;
}

int main()
{
    int maxN = -1;
    for(int i=0; i<2; i++) {
        scanf("%s", forInput[i]);
        int nowN = (int)strlen(forInput[i]);
        reverse(forInput[i], forInput[i]+nowN);
        maxN = max(maxN, (nowN+MOD_K-1) / MOD_K);
        for(int j=0; j<(nowN+MOD_K-1) / MOD_K; j++) {
            int nowV = 0;
            for(int k=(j+1)*MOD_K-1; k>=j*MOD_K; k--) if(k < nowN) nowV *= 10, nowV += forInput[i][k] - '0';
            A[i].push_back(nowV);
        }
    }
    for(int i=0; i<2; i++) {
        int nowN = (int)A[i].size();
        for(int j=nowN+1; j<=maxN; j++) A[i].push_back(0);
        //for(int j=maxN-1; j>=0; j--) printf("%d ", A[i][j]); puts("");
    }

    VI result = MULTI(A[0], A[1]);

    Print(result);
    return 0;
}

