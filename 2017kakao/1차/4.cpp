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

int toInt(string s) {
    int h, m;
    sscanf(s.c_str(), "%02d:%02d", &h, &m);
    return h*60 + m;
}
string toString(int k) {
    int h = k / 60, m = k % 60;
    char str[50];
    sprintf(str, "%02d:%02d", h, m);
    return string(str);
}
string solution(int N, int T, int M, vector<string> timetable) {
    vector<int> tt;
    int Tn = SZ(timetable);
    for(int i=0; i<Tn; i++) tt.push_back(toInt(timetable[i]));
    sort(ALL(tt));
    for(int t=9*60 + (N-1) * T, j=Tn-1; t>=0; t--) {
        while(j >= 0 && tt[j] > t) j--;
        tt.insert(tt.begin()+j+1, t);
        int ix = 0;
        for(int n=0; n<N; n++) {
            int cnt = 0, nowt = 9*60 + n * T;
            while(cnt < M && ix < Tn+1 && tt[ix] <= nowt) cnt++, ix++;
        }
        if(j+1 < ix) return toString(t);
        tt.erase(tt.begin()+j+1);
    }
    return toString(24*60);
}