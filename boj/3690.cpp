#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

map<char, int> Mp;
map<ll, ll> MemoS;

vector< pair<ll, int> > List;
int Chk[5];
int getType()
{
	//X 1 2 3 s f FH 4 Sf Rf
	int nr[5], co[5], cnt = 0;
	for(int i=0; i<5; i++)
		nr[cnt] = Chk[i] % 13, co[cnt++] = Chk[i] / 13;

	bool isFl = true;
	for(int i=1; i<5; i++) if(co[i] != co[0]) isFl = false;

	sort(nr, nr+5);
	bool isSt = true, best = false;
	for(int i=1; i<5; i++) if(nr[i] - nr[i-1] != 1) isSt = false;
	if(nr[0] == 0 && nr[1] == 1 && nr[2] == 2 && nr[3] == 3 && nr[4] == 12) isSt = true;
	if(nr[0] == 8 && nr[4] == 12 && isSt) best = true;

	if(best & isFl) return 9; // Rf
	if(isSt & isFl) return 8; // Sf

	int sameC = 0;
	for(int i=0, cnt = 0; i<5; i++)
	{
		if(i == 0 || nr[i] != nr[i-1]) cnt = 1;
		else cnt++;
		sameC = max(sameC, cnt);
	}

	if(sameC == 4) return 7;

	bool isFH = false;
	if(nr[0] == nr[1] && nr[1] != nr[2] && nr[2] == nr[3] && nr[3] == nr[4]) isFH = true; reverse(nr, nr+5);
	if(nr[0] == nr[1] && nr[1] != nr[2] && nr[2] == nr[3] && nr[3] == nr[4]) isFH = true; reverse(nr, nr+5);

	//X 1 2 3 s f FH 4 Sf Rf

	if(isFH) return 6;
	if(isFl) return 5;
	if(isSt) return 4;
	if(sameC == 3) return 3;
	if(sameC == 2)
	{
		if(nr[0] == nr[1] && nr[2] == nr[3]) return 2;
		if(nr[0] == nr[1] && nr[3] == nr[4]) return 2;
		if(nr[1] == nr[2] && nr[3] == nr[4]) return 2;
		return 1;
	}
	return 0;
}

void pre(int x, int mx, ll st)
{
	if(x == 5) 
	{
		int val = getType();
		if(val != 0)
			List.push_back(make_pair(st, val));
	}
	else for(int i=mx; i<52; i++) 
	{
		Chk[x] = i;
		pre(x+1, i+1, st | (1ll << i));
	}
}

int Sc[10], Calc[10];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	pre(0, 0, 0);
	char nrs[99] = "23456789TJQKA", cos[99] = "cdhs";
	for(int i=0; i<13; i++) Mp[nrs[i]] = i;
	for(int i=0; i<4; i++) Mp[cos[i]] = i*13;
	Calc[0] = 1;
	for(int i=1; i<=5; i++) Calc[i] = Calc[i-1] * (47 - i + 1) / i;

	int T; scanf("%d", &T);
	while(T--)
	{
		for(int i=1; i<=9; i++) scanf("%d", &Sc[i]);
		int Q; scanf("%d", &Q);
		while(Q--)
		{
			MemoS.clear();
			ll now = 0;
			for(int i=0; i<5; i++)
			{
				char in[10]; scanf("%s", in);
				now |= (1ll << (Mp[in[0]] + Mp[in[1]]));
			}
			for(pair<ll, int> &l : List)
			{
				ll next = l.first; int sc = Sc[l.second];
				MemoS[next & now] += sc;
			}
			double ans = 0;
			for(auto &m : MemoS)
			{
				int cnt = 0;
				ll sc = m.second, st = m.first, temp = st;
				while(temp)
				{
					temp &= (temp - 1);
					cnt++;
				}
				ans = max(ans, (double)sc / Calc[5-cnt] );
			}
			printf("%.10lf\n", ans);
		}
	}
	return 0;
}