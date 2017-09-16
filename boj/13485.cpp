#include <stdio.h>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

const int MAX_N = 1e5 + 100;

int N; char Mp[11][MAX_N];
int Dy[11][MAX_N]; // 1 up 2 down 3 impossible
int main()
{
	scanf("%d", &N); for(int i=0; i<10; i++) scanf("%s", Mp[i]);
	for(int i=0; i<10; i++) Dy[i][0] = -1;
	Dy[9][0] = 0;
	for(int j=1; j<N; j++)
	{
		for(int i=0; i<10; i++) Dy[i][j] = -1;
		for(int i=0; i<10-1; i++)
			if(Dy[i+1][j-1] >= 0)
				Dy[i][j] = 1;
		for(int i=1; i<10; i++)
			if(Dy[i-1][j-1] >= 0)
				Dy[i][j] = 0;
		if(Dy[9][j-1] >= 0) Dy[9][j] = 0;
		if(Dy[0][j-1] >= 0) Dy[0][j] = 1;
		for(int i=0; i<10; i++) if(Mp[i][j] == 'X') Dy[i][j] = -1;
	}
	for(int i=0; i<10; i++)
		if(Dy[i][N-1] >= 0)
		{
			deque<int> List;
			int k = i;
			for(int j=N-1; j>=1; j--)
			{
				if(Dy[k][j] == 1) List.push_front(j-1);
				if(Dy[k][j] == 1) 
				{
					k = k+1;
					if(k == 1 && Dy[k][j-1] == -1) k = 0;
				}
				else if(Dy[k][j] == 0) 
				{
					k = k-1;
					if(k == 8 && Dy[k][j-1] == -1) k = 9;
				}
			}
			vector<pair<int, int> > Ans;
			int cnt = 0, past = 0;
			for(int i=0; i<List.size(); i++)
			{
				if(i == 0 || List[i-1]+1 != List[i])
					past = List[i], cnt = 0;
				cnt++;
				if(i == ((int)List.size()-1) || List[i]+1 != List[i+1])
					Ans.push_back(make_pair(past, cnt));
			}
			printf("%d\n", (int)Ans.size());
			for(auto &t : Ans) printf("%d %d\n", t.first, t.second);
			return 0;
		}
	return 0;
}