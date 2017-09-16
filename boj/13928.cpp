#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 50, MAX_M = 500;

bool Chk[MAX_N][MAX_N * 4];
vector<int> Dy[MAX_N][MAX_N * 4], Nr[MAX_N];
int N, M, From[MAX_N][MAX_N * 4];

bool getOp(vector<int> &bi, vector<int> &sm, vector<int> &op, int l)
{
	op = bi;
	int nowl = l, last = -1;
	for(int i=0; i<M; i++) if(op[i] != sm[i] && nowl)
	{
		op[i] = sm[i];
		nowl--;
		last = i;
	}
	if(sm <= op) return true;

	int ch = -1;
	for(int i=last; i>=0; i--) if(sm[i] != 9) { ch = i; break; }
	if(ch == -1) return false;

	op = bi;
	nowl = l;
	for(int i=0; i<ch; i++) if(op[i] != sm[i]) {op[i] = sm[i]; nowl--; }
	if(bi[ch] != sm[ch] + 1)
	{
		op[ch] = sm[ch] + 1;
		nowl--;
	}
	for(int i=ch+1; i<M; i++) if(bi[i] != 0 && nowl)
	{
		op[i] = 0;
		nowl--;
	}
	return true;
}

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++) for(int j=0, x; j<M; j++) scanf("%1d", &x), Nr[i].push_back(x);

	Chk[0][0] = true;
	for(int i=0; i<=N; i++) for(int j=0; j<N*4; j++) Dy[i][j] = vector<int>(M, 0);
	for(int i=0; i<N; i++) for(int j=0; j<N*4; j++)
	{
		if(Chk[i][j] == false) continue;
		vector<int> op; op.reserve(M);
		for(int k=0; j+k<N*4; k++)
		{
			if(getOp(Nr[i+1], Dy[i][j], op, k))
			{
				if(Chk[i+1][j+k] == false || Dy[i+1][j+k] > op)
				{
					Chk[i+1][j+k] = true;
					Dy[i+1][j+k] = op;
					From[i+1][j+k] = j;
				}
			}
		}
	}

	for(int j=0; j<N*4; j++) if(Chk[N][j])
	{
		vector<int> ixs;
		int ix = j;
		for(int i=N; i>=1; i--)
		{
			ixs.push_back(ix);
			ix = From[i][ix];
		}
		ixs.push_back(0);
		reverse(ixs.begin(), ixs.end());
		for(int i=1; i<=N; i++, puts("")) for(int x : Dy[i][ixs[i]]) printf("%d", x);
		break;
	}
	return 0;
}