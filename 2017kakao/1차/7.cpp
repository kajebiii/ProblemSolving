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

pi getInput(string str) {
    int h, m, s, ms; double t;
    sscanf(str.c_str(), "2016-09-15 %02d:%02d:%02d.%03d %lfs", &h, &m, &s, &ms, &t);
    int en = h*3600000 + m*60000 + s*1000 + ms;
    int st = en - (t * 1000) + 1;
    return pi(st, en);
}
int solution(vector<string> lines) {
    int n = SZ(lines);
    vector<int> St, En;
    for(int i=0; i<n; i++) {
        int st, en; tie(st, en) = getInput(lines[i]);
        St.push_back(st); En.push_back(en);
    }
    sort(ALL(St)); sort(ALL(En));

    int cnt = 0, ans = 0;
    for(int t=0, s=0, e=0; t<24*3600000; t++) {
        while(s < n && St[s] < t+1000) s++, cnt++;
        while(e < n && En[e] < t) e++, cnt--;
        ans = max(ans, cnt);
    }
    return ans;
}