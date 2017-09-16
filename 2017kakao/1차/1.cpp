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

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    for(int i=0; i<n; i++) {
        for(int j=n-1; j>=0; j--) {
            res[i][j] |= (arr1[i] & 1) | (arr2[i] & 1);
            arr1[i] >>= 1;
            arr2[i] >>= 1;
        }
    }
    vector<string> Ans(n);
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) 
        Ans[i] += (res[i][j] ? '#' : ' ');
    return Ans;
}