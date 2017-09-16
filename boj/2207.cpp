#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

const int MAX_N = 2e4 + 100;

int N, M;
vector<int> Ed[MAX_N];
int gnot(int v) {return (v+N)%(2*N);}
void gor(int a, int b){Ed[gnot(a)].push_back(b), Ed[gnot(b)].push_back(a); }

int Ix[MAX_N], IN, Gp[MAX_N], GN; stack<int> S;
int getLow(int v)
{
	int low = Ix[v] = ++IN; S.push(v);
	for(int w : Ed[v])
		if(Ix[w] == 0) low = min(low, getLow(w));
		else if(Gp[w] == 0) low = min(low, Ix[w]);
	if(low == Ix[v])
		for(++GN; 1;)
		{
			int now = S.top(); S.pop();
			Gp[now] = GN;
			if(now == v) break;
		}
	return low;
}
int main()
{
	scanf("%d%d", &M, &N);
	for(int _=0; _<M; _++)
	{
		int x, y; scanf("%d%d", &x, &y);
		if(x < 0) x = -x + N; x--;
		if(y < 0) y = -y + N; y--;
		gor(x, y);
	}
	for(int i=0; i<2*N; i++) if(Ix[i] == 0) getLow(i);
	bool isTrue = true;
	for(int i=0; i<N; i++) if(Gp[i] == Gp[gnot(i)]) isTrue = false;
	if(isTrue) puts("^_^");
	else puts("OTL");
	return 0;
}