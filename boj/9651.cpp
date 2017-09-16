#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;

const int MAX_N = 1e3 + 100;
typedef long long ll;
typedef pair<ll, ll> pl;
const ll LINF = 0x7fffffffffffffff;

int N;
char S[MAX_N];
bool Visit[MAX_N][MAX_N];
pl Dy[MAX_N][MAX_N], imp = make_pair(LINF, -LINF);
pl get(int a, int b)
{
	if(Visit[a][b]) return Dy[a][b];
	Visit[a][b] = true;
	if(a > b) return imp;
	if(S[a] >= '0' && S[a] <= '9')
	{
		if(b - a > 8) return imp;
		if(S[a] == '0' && b - a > 0) return imp;
		ll now = 0;
		for(int i=a+1; i<=b; i++) if(S[i] < '0' || S[i] > '9') return imp;
		for(int i=a; i<=b; i++) now *= 10, now += (S[i] - '0');
		Dy[a][b] = make_pair(now, now);
	}
	else
	{
		if(S[b] < '0' || S[b] > '9') return imp;
		pl res = imp;
		for(int i=a+1; i<b; i++)
		{
			pl l = get(a+1, i), r = get(i+1, b);
			if(l.first == LINF || r.first == LINF) continue;
			if(S[a] == '-') swap(r.first, r.second), r.first *= -1, r.second *= -1;
			res.first  = min(res.first , l.first  + r.first);
			res.second = max(res.second, l.second + r.second);
		}
		if(S[a] == '-')
		{
			pl r = get(a+1, b);
			if(r.first != LINF)
			{
				res.first  = min(res.first , -r.second);
				res.second = max(res.second, -r.first);
			}
		}
		Dy[a][b] = res;
	}
//	printf("%d %d : %lld %lld\n", a, b, Dy[a][b].first, Dy[a][b].second);
	return Dy[a][b];
}

int main()
{
	while(scanf("%s", S) != EOF)
	{
		N = (int)strlen(S);
		for(int i=0; i<N; i++) for(int j=0; j<N; j++) Dy[i][j].first = LINF, Dy[i][j].second = -LINF, Visit[i][j] = false;
		pl ans = get(0, N-1);
		printf("%lld %lld\n", ans.first, ans.second);
	}
	return 0;
}