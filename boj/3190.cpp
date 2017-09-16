#include <stdio.h>
#include <algorithm>
#include <vector>
#include <deque>
#include <tuple>

using namespace std;

const int MAX_N = 1e2 + 10;
typedef pair<int, int> pi;

int Apple[MAX_N][MAX_N], Chk[MAX_N][MAX_N];
int N, K, L; char Data[11111];
deque<pi> List;
// "1210"[k] - '1', "2101"[k] -  '1' [left -> right]

int main() {
	scanf("%d%d", &N, &K);
	while(K--) {
		int x, y; scanf("%d%d", &x, &y);
		Apple[x][y] = 1;
	}
	scanf("%d", &L);
	for(int i=0; i<L; i++) {
		char data[9]; int x; scanf("%d %s", &x, data);
		Data[x] = data[0];
	}
	int X = 1, Y = 1, D = 0, T = 0;
	List.push_back(make_pair(X, Y)); Chk[X][Y] = 1;
	while(1) {
		X += "1210"[D] - '1';
		Y += "2101"[D] - '1';
		T++;
		if(Data[T] == 'D') D = (D+1) % 4;
		else if(Data[T] == 'L') D = (D+3) % 4;
		if(X <= 0 || Y <= 0) break;
		if(X > N || Y > N) break;
		if(Chk[X][Y] == 1) break;
		List.push_back(make_pair(X, Y)); Chk[X][Y] = 1;
		int x, y; tie(x, y) = List.front(); 
		if(Apple[X][Y] == 0) {
			List.pop_front(); Chk[x][y] = 0;
		}else{Apple[X][Y] = 0;}
	}
	printf("%d\n", T);
	return 0;
}