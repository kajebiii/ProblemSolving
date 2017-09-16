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

int solution(int cs, vector<string> city) {
    int n = SZ(city);
    for(int i=0; i<n; i++) for(int j=0; j<SZ(city[i]); j++) 
        if(city[i][j] >= 'a' && city[i][j] <= 'z')
            city[i][j] += 'A' - 'a';

 .,ㅡ    set<string> List;
    map<string, int> Last;
    const int HIT = 1, MISS = 5;
    int ans = 0;
    for(int i=0; i<n; i++) Last[city[i]] = -1;
    for(int i=0; i<n; i++) {
        if(List.find(city[i]) == List.end()) {
            if(cs > 0 && SZ(Mp) == cs) {
                List.erase(Mp.begin()->second);
                Mp.erase(Mp.begin());
            }
            if(cs > 0) {
                Mp.insert(make_pair(Last[city[i]] = i , city[i]));
                List.insert(city[i]);
            }
            ans += MISS;
        }else{
            int last = Last[city[i]];
            Mp.erase(last);
            Mp.insert(make_pair(Last[city[i]] = i, city[i]));
            ans += HIT;
        }
    }
    return ans;
}