#include <stdio.h>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> Nr;
deque<int> dq;
int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0, x; i<N; i++) scanf("%d", &x), Nr.push_back(x);
	for(int i=0; i<N; i++)
	{
		while(!dq.empty() && dq.front() <= i - 2*M + 1) dq.pop_front();
		while(!dq.empty() && Nr[dq.back()] <= Nr[i]) dq.pop_back();
		dq.push_back(i);
		if(i >= 2*M-2) printf("%d ", Nr[dq.front()]);
	}
	return 0;
}