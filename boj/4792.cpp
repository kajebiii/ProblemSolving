#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct ED {
	int x, y; char c;
	ED() {}
	ED(int x_, int y_, char c_) : x(x_), y(y_), c(c_) {}
};
const int MAX_N = 1e3 + 10;
vector<ED> List; 
int N, M, B;
int UNF[MAX_N];
int F(int v) { return v==UNF[v]?v:UNF[v]=F(UNF[v]); }
bool U(int a, int b) {a=F(a);b=F(b); UNF[F(a)] = F(b); return a != b; }
int main() {
	while(1) {
		scanf("%d%d%d", &N, &M, &B);
		List.clear();
		if(N+M+B == 0) break;
		for(int _=0; _<M; _++) {
			char c; int x, y; scanf(" %c%d%d", &c, &x, &y);
			List.push_back(ED(x, y, c));
		}
		
		sort(List.begin(), List.end(), [&](auto &a, auto &b){return a.c<b.c;});
		for(int i=1; i<=N; i++) UNF[i] = i;
		int cnt = 0;
		for(ED &e : List) if(U(e.x, e.y)) cnt++;
		for(int i=1; i<=N; i++) UNF[i] = i;
		int maxB = 0, minB = 0;
		for(ED &e : List) if(U(e.x, e.y) && e.c == 'B') maxB++;
		reverse(List.begin(), List.end());
		for(int i=1; i<=N; i++) UNF[i] = i;
		for(ED &e : List) if(U(e.x, e.y) && e.c == 'B') minB++;
			
		if(cnt == N-1 && minB <= B && B <= maxB) puts("1"); else puts("0");
	}
	return 0;
}