#include <stdio.h>
#include <functional>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string.h>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <math.h>
 
using namespace std;
 
typedef pair<int, int> pi;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) { return mp(x.fi+y.fi, x.se+y.se); }
 
const int INF = 0x7fffffff;
const pi Ch[4] ={ mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1) };
 
const int MAX_N = 1e5 + 100;
 
pi L[MAX_N];
int N, Y;
int Dis(pi x) { return Y + abs(x.fi - x.se); }
 
map<int, int> Ix; int IxN;
ll T[MAX_N];
 
int main() {
    if(debug) freopen("input.txt", "r", stdin);
 
    cin >> N >> Y;
    for(int i=0; i<N; i++) scanf("%d%d", &L[i].fi, &L[i].se);
    vector<int> Down;
    for(int i=0; i<N; i++) Down.pb(L[i].se);
    Down.resize(unique(Down.begin(), Down.end()) - Down.begin());
    int ixN = (int)Down.size();
    for(int i=0; i<ixN; i++)
        Ix[Down[i]] = i;
 
    sort(L, L+N);
 
    ll ans = 0;
    for(int p=0; p<N; )
    {
        int i;
        ll nowMax = 0;
        for(i=p; L[i].fi == L[p].fi && i<N; i++)
        {
            ll temp = nowMax;
            nowMax = max(T[Ix[L[i].se]] + Dis(L[i]), nowMax);
            T[Ix[L[i].se]] = max(T[Ix[L[i].se]], temp + Dis(L[i]));
        }
        ans = max(ans, nowMax);
        p = i;
    }
    for(int i=0; i<ixN; i++)
        ans = max(ans, T[i]);
 
    cout << ans;
    return 0;
}
