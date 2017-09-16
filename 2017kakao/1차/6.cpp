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

int solution(int n, int m, vector<string> bd) {
    int ans = 0;
    bool update = false;
    do {
        update = false;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i+1<n; i++) for(int j=0; j+1<m; j++) if(bd[i][j] != 'x') {
            bool isSame = true;
            for(int k=0; k<3; k++) {
                int x = i + "011"[k] - '0', y = j + "101"[k] - '0';
                if(bd[x][y] != bd[i][j]) { isSame = false; break; }
            }
            if(isSame) {
                update = true;
                for(int k=0; k<4; k++) {
                    int x = i + "0011"[k] - '0', y = j+"0101"[k] - '0';
                    vis[x][y] = true;
                }
            }
        }

        for(int i=0; i<n; i++) for(int j=0; j<m; j++) if(vis[i][j]) bd[i][j] = 'x', ans++;
        for(int j=0; j<m; j++) {
            int ix = n-1;
            for(int i=n-1; i>=0; i--) if(bd[i][j] != 'x') bd[ix--][j] = bd[i][j];
            for(int i=ix; i>=0; i--) bd[i][j] = 'x';
        }
    }while(update == true);
    return ans;
}