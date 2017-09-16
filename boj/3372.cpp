#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;

vi operator+(const vi &a, const vi &b)
{
	
	vi res = vector<int>(max(a.size(), b.size())+1, 0);
	for(int i=0; i<a.size(); i++) res[i] += a[i];
	for(int i=0; i<b.size(); i++) res[i] += b[i];
	for(int i=0; i<max(a.size(), b.size()); i++)
		res[i+1] += res[i] / 10, res[i] %= 10;
	return res;
}

const int MAX_N = 1e2 + 50;

int N; vi Dy[MAX_N][MAX_N]; int Nr[MAX_N][MAX_N];
void print(vi v)
{
	int last = (int)v.size() - 1;
	bool notZ = false;
	for(int i=last; i>=0; i--)
	{
		if(v[i] != 0) notZ = true;
		if(notZ) printf("%d", v[i]);
	}
	if(notZ == false) printf("0");
	puts("");
}

int main()
{
	scanf("%d", &N);
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) scanf("%d", &Nr[i][j]);
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) Dy[i][j].push_back(0);
	Dy[1][1][0] = 1;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
	{
		int Ch[2][2] = {{1, 0}, {0, 1}};
		if(Nr[i][j] == 0) continue;
		for(int k=0; k<2; k++)
		{
			int x = i + Ch[k][0] * Nr[i][j], y = j + Ch[k][1] * Nr[i][j];
			if(x <= N && y <= N)
				Dy[x][y] = Dy[x][y] + Dy[i][j];
		}
	}
	print(Dy[N][N]);
	return 0;
}