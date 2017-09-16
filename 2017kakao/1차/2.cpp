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

int solution(string dart) {
    vector<int> res(4, 0);
    int n = SZ(dart);
    int nowNr = 0, ix = 0;
    for(int i=0, j=0; i<n; i=j) {
        if(dart[i] >= '0' && dart[i] <= '9') {
            nowNr = dart[i] - '0'; j = i+1;
            if(i+1 < n && dart[i+1] == '0') nowNr = 10, j = i+2;
            ix++;
        }
        while(j < n && (dart[j] < '0' || dart[j] > '9')) {
            for(int k=1; k<=3; k++) if(dart[j] == " SDT"[k]) {
                int plusV = 1;
                for(int o=0; o<k; o++) plusV *= nowNr;
                res[ix] += plusV;
            }
            if(dart[j] == '*') for(int k=ix-1; k<=ix; k++) res[k] *= 2;
            if(dart[j] == '#') res[ix] *= -1;
            j++;
        }
    }
    int ans = 0;
    for(int i=0; i<4; i++) ans += res[i];
    return ans;
}