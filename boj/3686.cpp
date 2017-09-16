#include <stdio.h>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

const int MAX_N = 1e2 + 10;

#define mt make_tuple
typedef tuple<int, int, int> ti;

int R[MAX_N][3][2];
int V[MAX_N][MAX_N][MAX_N];
vector<int> C[3];
int N;

int bit(int n, int l)
{
	if(n & (1<<l)) return 1;
	return 0;
}
int pm(int n)
{
	int p = 1;
	for(int i=0; i<3; i++)
		if(n & (1<<i)) p *= -1;
	return p;
}

int Chk[MAX_N][MAX_N][MAX_N];
ti Ch[6] = {mt(0, 0, 1), mt(0, 0, -1), mt(0, 1, 0), mt(0, -1, 0), mt(1, 0, 0), mt(-1, 0, 0)};
ti operator+(ti &x, ti &y) 
{ 
	int a[3], b[3];
	tie(a[0], a[1], a[2]) = x;
	tie(b[0], b[1], b[2]) = y;
	return mt(a[0]+b[0], a[1]+b[1], a[2]+b[2]);
}


void delMemo()
{
	for(int i=0; i<C[0].size(); i++) for(int j=0; j<C[1].size(); j++) for(int k=0; k<C[2].size(); k++) V[i][j][k] = Chk[i][j][k] = 0;
	for(int i=0; i<3; i++)
	{
		vector<int> temp;
		C[i].swap(temp);
	}
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		for(int i=1; i<=N; i++) for(int k=0; k<2; k++) for(int j=0; j<3; j++) scanf("%d", &R[i][j][k]);
		for(int i=1; i<=N; i++) for(int j=0; j<3; j++) R[i][j][1] += R[i][j][0];
		for(int i=1; i<=N; i++) for(int k=0; k<2; k++) for(int j=0; j<3; j++) C[j].push_back(R[i][j][k]);
		for(int i=0; i<3; i++) C[i].push_back(0);
		for(int i=0; i<3; i++) sort(C[i].begin(), C[i].end());
		for(int i=0; i<3; i++) C[i].resize(unique(C[i].begin(), C[i].end()) - C[i].begin());
		for(int i=1; i<=N; i++) for(int j=0; j<3; j++) for(int k=0; k<2; k++)
			R[i][j][k] = lower_bound(C[j].begin(), C[j].end(), R[i][j][k]) - C[j].begin();
		for(int i=1; i<=N; i++) for(int j=0; j<8; j++)
			V[R[i][0][bit(j,0)]][R[i][1][bit(j, 1)]][R[i][2][bit(j, 2)]] += pm(j);
		for(int i=1; i<C[0].size(); i++) for(int j=1; j<C[1].size(); j++) for(int k=1; k<C[2].size(); k++)
			V[i][j][k] += V[i-1][j][k] + V[i][j-1][k] + V[i][j][k-1] - V[i-1][j-1][k] - V[i][j-1][k-1] - V[i-1][j][k-1] + V[i-1][j-1][k-1];

		int area = 0;
		queue<ti> Q; Q.push(mt(0, 0, 0)); Chk[0][0][0] = 1;
		while(!Q.empty())
		{
			ti now = Q.front(); Q.pop();
			int no[3]; tie(no[0], no[1], no[2]) = now;
			for(int k=0; k<6; k++)
			{
				int nt[3];
				ti next = now + Ch[k];
				tie(nt[0], nt[1], nt[2]) = next;
				bool isGood = true;
				for(int i=0; i<3; i++) if(nt[i] < 0 || nt[i] >= C[i].size()) isGood = false;
				if(!isGood) continue;
				if(Chk[nt[0]][nt[1]][nt[2]] == 1) continue;
				if(V[nt[0]][nt[1]][nt[2]] > 0)
				{
					int nowA = 1;
					for(int i=0; i<3; i++) if(nt[i] == no[i])
						nowA *= C[i][nt[i]+1] - C[i][nt[i]];
					area += nowA;
				}
				else
				{
					Chk[nt[0]][nt[1]][nt[2]] = 1;
					Q.push(next);
				}
			}
		}

		int volume = 0;
		for(int i=1; i<C[0].size(); i++) for(int j=1; j<C[1].size(); j++) for(int k=1; k<C[2].size(); k++)
			if(Chk[i][j][k] == 0)
				volume += (C[0][i+1] - C[0][i]) * (C[1][j+1] - C[1][j]) * (C[2][k+1] - C[2][k]);
		

		printf("%d %d\n", area, volume);


		delMemo();
 	}
	return 0;
}