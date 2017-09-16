#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<double, double> pd;
typedef pair<int, int> pi; typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;  typedef pair<ll, pi> plp;
typedef pair<int, pi> pip; typedef tuple<int, int, int> ti;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

bool isBetween(char k, char x, char y) {
    return x <= k && k <= y;
}
int solution(string str1, string str2) {
    string str[2] = {str1, str2};
    vector<string> S[2];
    for(int k=0; k<2; k++) for(int i=0; i<SZ(str[k]); i++)
        if(isBetween(str[k][i], 'a', 'z')) str[k][i] += 'A' - 'a';
    for(int k=0; k<2; k++) for(int i=0; i+1<SZ(str[k]); i++) {
        if(isBetween(str[k][i], 'A', 'Z') && isBetween(str[k][i+1], 'A', 'Z')) {
            char temp[3] = {str[k][i], str[k][i+1], 0};
            S[k].push_back(string(temp));
        }
        sort(ALL(S[k]));
    }
    if(SZ(S[0]) + SZ(S[1]) == 0) return 65536;

    int inter = 0;
    int ix[2] = {0, 0};
    while(ix[0] < SZ(S[0]) && ix[1] < SZ(S[1])) {
        string c[2] = {S[0][ix[0]], S[1][ix[1]]};
        if(c[0] == c[1]) ix[0]++, ix[1]++, inter++;
        else if(c[0] > c[1]) ix[1]++; else ix[0]++;
    }
    return inter * 65536 / (SZ(S[0]) + SZ(S[1]) - inter);
}