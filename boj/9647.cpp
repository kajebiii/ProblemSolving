#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int MAX_O = 16e4;
typedef long long ll;

bool notP[MAX_O]; int Dy[MAX_O];
map<int, int> Mp[MAX_O]; int maxEx[MAX_O];
int ggcd(int a, int b) { return b==0?a:ggcd(b, a%b); }
void preprocess()
{
	for(int i=2; i<MAX_O; i++)
	{
		if(notP[i] == true) continue;
		for(int j=i; j<MAX_O; j+=i)
		{
			notP[j] = true;
			int k = j, cnt = 0;
			while(k % i == 0) { k /= i; cnt++; }
			Mp[j][i] = cnt;
		}
	}
	Dy[1] = 0;
	for(int i=2; i<MAX_O; i++)
	{
		int gcd = 0;
		for(auto &t : Mp[i]) gcd = ggcd(gcd, t.second);
		maxEx[i] = gcd;
		for(int k=2; k<=gcd; k++) if(gcd % k == 0)
			Dy[i] += Dy[k];
		Dy[i]++; // when k is 1;
	}
}
int main()
{
	preprocess();
	int a, b, c;
	while(scanf("%d^%d^%d", &a, &b, &c) == 3)
	{
		long long ans = 0;
		int k = maxEx[a];
		map<int, int> now;
		for(auto &t : Mp[k]) now[t.first] += t.second;
		for(auto &t : Mp[b]) now[t.first] += t.second * c;
		int maxV = -1;
		vector<int> list;
		for(auto &t : now) maxV = max(maxV, t.second), list.push_back(t.second);
		for(int i=2; i<=maxV; i++)
		{
			ll nowV = 1;
			for(int x : list) nowV *= (x / i + 1);
			nowV--;
			ans += nowV * Dy[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}