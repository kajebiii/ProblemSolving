#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX_N = 1e5 + 100;
typedef long long ll;

ll pm, pM, mm, mM, D;
int N, Nr[MAX_N][2];
vector<ll> Xs, Ys;
ll Xb[MAX_N][2], Yb[MAX_N][2];

ll calc(ll x, ll y)
{
	int px = upper_bound(Xs.begin(), Xs.end(), x) - Xs.begin();
	int py = upper_bound(Ys.begin(), Ys.end(), y) - Ys.begin();
	ll xl = (px==0?0 : Xb[px-1][0] + 1ll * px * (x - Xs[px-1]));
	ll xr = (px==N?0 : Xb[px][1] + 1ll * (N-px) * (Xs[px] - x));
	ll yl = (py==0?0 : Yb[py-1][0] + 1ll * py * (y - Ys[py-1]));
	ll yr = (py==N?0 : Yb[py][1] + 1ll * (N-py) * (Ys[py] - y));
	return xl+xr+yl+yr;
}

int main()
{
	scanf("%d", &N); for(int i=0; i<N; i++) for(int j=0; j<2; j++) scanf("%d", &Nr[i][j]); scanf("%lld", &D);
	for(int i=0; i<N; i++) Xs.push_back(Nr[i][0]), Ys.push_back(Nr[i][1]);
	sort(Xs.begin(), Xs.end()); sort(Ys.begin(), Ys.end());
	for(int i=1; i<N; i++)
	{
		Xb[i][0]	 = Xb[i-1][0] + 1ll * i * (Xs[i] - Xs[i-1]);
		Xb[N-1-i][1] = Xb[N-i][1] + 1ll * i * (Xs[N-i] - Xs[N-1-i]);
	}
	for(int i=1; i<N; i++)
	{
		Yb[i][0]	 = Yb[i-1][0] + 1ll * i * (Ys[i] - Ys[i-1]);
		Yb[N-1-i][1] = Yb[N-i][1] + 1ll * i * (Ys[N-i] - Ys[N-1-i]);
	}

	pm = mm = -0x7fffffffffff; pM = mM = +0x7fffffffffff;
	for(int i=0; i<N; i++)
	{
		ll nowp = Nr[i][0] + Nr[i][1], nowm = Nr[i][1] - Nr[i][0];
		pm = max(pm, nowp - D); pM = min(pM, nowp + D);
		mm = max(mm, nowm - D); mM = min(mM, nowm + D);
	}
	if(pm > pM || mm > mM) {puts("impossible"); return 0;}

	vector<int> candi;
	for(int t=0; t<2; t++)
	{
		candi.push_back((pm - mm + t) / 2);
		candi.push_back((pM - mm + t) / 2);
		candi.push_back((pm - mM + t) / 2);
		candi.push_back((pM - mM + t) / 2);
	}
	for(int i=0; i<N; i++) 
		candi.push_back(Nr[i][0]);
	for(int i=0; i<N; i++)
	{
		candi.push_back(Nr[i][1] - mm);
		candi.push_back(Nr[i][1] - mM);
		candi.push_back(pm - Nr[i][1]);
		candi.push_back(pM - Nr[i][1]);
	}
	sort(candi.begin(), candi.end());
	candi.erase(unique(candi.begin(), candi.end()), candi.end());
	
	ll ans = 0x7fffffffffffffff;
	for(int x : candi)
	{
		int ym = max(pm - x, mm + x);
		int yM = min(pM - x, mM + x);
		if(ym > yM) continue;

		if(ym <= Ys[N/2] && Ys[N/2] <= yM)
			ans = min(ans, calc(x, Ys[N/2]));
		else
			ans = min(ans, min(calc(x, ym), calc(x, yM)));
	}
	printf("%lld\n", ans);
	return 0;
}

