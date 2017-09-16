#include <stdio.h>
#include <string.h>
#include <deque>

using namespace std;

const int MAX_N = 1e4 + 100;
typedef pair<int, int> pi;
typedef long long ll;

ll K;
int N;
char S[MAX_N];
deque<pi> Q;

bool impossible;
void find(int a, int b)
{
	int m = (a+b)/2, baseR = m + 1;

	if((a + b) % 2 == 0)
	{
		if(S[m] == '?')
			if(m == 1) Q.push_front(make_pair(m, 9));
			else Q.push_front(make_pair(m, 10));
		m--;
	}else impossible = true;

	if((a+b) == 2) return;
	for(int i=a, cnt=0; i<=m; i++, cnt++)
	{
		int l = a + cnt, r = baseR + cnt;
		if(S[l] != S[r])
		{
			if(S[l] != '?' && S[r] != '?') impossible = true;
			else if(S[l] == '?') S[l] = S[r];
			else S[r] = S[l];
		}//else means Same
		if(l == 1 && S[l] == '0') impossible = true;
	}
	find(a, m);
	for(int i=a, cnt=0; i<=m; i++, cnt++)
	{
		int l = a + cnt, r = baseR + cnt;
		if(S[l] != S[r])
		{
			if(S[l] != '?' && S[r] != '?') impossible = true;
			else if(S[l] == '?') S[l] = S[r];
			else S[r] = S[l];
		}//else means Same
		if(l == 1 && S[l] == '0') impossible = true;
	}
}

int Chk[10], Change[10];
int main()
{
	while(1)
	{
		scanf("%lld", &K); if(K == 0) break;
		K--;
		scanf("%s", S+1); N = strlen(S+1);
		Q.clear();
		impossible = false;
		find(1, N);
		for(int i=1; i<N; i++) if(S[i] == S[i+1] && S[i] != '?') impossible = true;
		if(impossible) {puts("-1"); continue;}

		for(int i=0; i<10; i++) Chk[i] = 0;
		for(int i=2; i<N; i+=2) if(S[i] != '?') Chk[S[i]-'0'] = 1;
		if(S[1] != '?') {for(int i=0; i<10; i++) Chk[i] = 1; Chk[S[1]-'0'] = 0;}
		else Q.pop_front();

		ll baseCnt = 1, all = 0;
		for(int i=0; i<Q.size(); i++) baseCnt *= 9;
		for(int i=1; i<10; i++) if(Chk[i] == 0) all += baseCnt;
		if(all <= K) {puts("-1"); continue; }

		for(int p=1; p<10; p++)
		{
			if(Chk[p] == 1) continue;
			if(K >= baseCnt) {K -= baseCnt; continue;}
			for(int j=0; j<p; j++) Change[j] = j;
			for(int j=p; j<9; j++) Change[j] = j+1;
			
			for(int j=0; j<Q.size(); j++)
			{
				S[Q[Q.size()-j-1].first] = Change[K % 9] + '0';
				K /= 9;
			}
			S[1] = p + '0';
			break;
		}
		find(1, N);
		printf("%s\n", S+1);
	}

	return 0;
}