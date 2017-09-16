#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e2 + 10, MAX_D = 2e1 + 5;

double Dy[MAX_N][MAX_N]; bool Visit[MAX_N][MAX_N];
int D, N, M;
int A[3][MAX_D][MAX_D]; //use k+1 dice;
int Cnt[3][2][3][3], More[3][2][MAX_D][MAX_D][3][3];

void dice() {
	for(int k=0; k<3; k++) for(int i=1; i<=D; i++) for(int j=0; j<=D; j++)
		A[k][i][j] = 0;
	for(int i=1; i<=D; i++) for(int j=1; j<=D; j++) for(int k=1; k<=D; k++) {
		vector<int> list = vector<int>({i, j, k});
		sort(list.begin(), list.end(), [&](int &a, int &b) {return a>b;});
		A[2][list[0]][list[1]]++;
	}
	for(int i=1; i<=D; i++) for(int j=1; j<=D; j++) {
		int x = i, y = j; if(x<y) swap(x, y);
		A[1][x][y]++;
	}
	for(int i=1; i<=D; i++)
		A[0][i][0]++;


	for(int at=0; at<3; at++) for(int de=0; de<2; de++) {
		for(int ap=0; ap<3; ap++) for(int dp=0; dp<3; dp++)
			Cnt[at][de][ap][dp] = 0;
		for(int ax=1; ax<=D; ax++) for(int ay=0; ay<=D; ay++)
			for(int ap=0; ap<3; ap++) for(int dp=0; dp<3; dp++)
				More[at][de][ax][ay][ap][dp] = 0;
		for(int ax=1; ax<=D; ax++) for(int ay=0; ay<=D; ay++)
			for(int dx=1; dx<=D; dx++) for(int dy=0; dy<=D; dy++)
				if(A[at][ax][ay] > 0 && A[de][dx][dy] > 0) {
					int a=0, d=0;
					if(ax > dx) d++; else a++;
					if(ay != 0 && dy != 0) { if(ay > dy) d++; else a++; }
					Cnt[at][de][a][d] += A[at][ax][ay] * A[de][dx][dy];
					More[at][de][ax][ay][a][d] += A[at][ax][ay] * A[de][dx][dy];
				}
	}
}
double getDy(int n, int m) {
	if(Visit[n][m]) return Dy[n][m];
	Visit[n][m] = true;
	double &res = Dy[n][m];
	if(n == 1) return res = 0;
	if(m == 0) return res = 1;
	int at = min(3, (n-1)) - 1;
	int deM = min(2, m) - 1;
	double val[2] ={0, 0};
	int cnt[2] = {0, 0};

	for(int de=0; de<=deM; de++)
		for(int i=0; i<3; i++) for(int j=0; j<3; j++)
			cnt[de] += Cnt[at][de][i][j];
	res = 0;
	for(int ax=1; ax<=D; ax++) for(int ay=0; ay<=D; ay++) {
		double now = 1.1;
		for(int de=0; de<=deM; de++) {
			val[de] = 0;
			for(int i=0; i<3; i++) for(int j=0; j<3; j++)
				if(More[at][de][ax][ay][i][j] > 0)
					val[de] += (double)More[at][de][ax][ay][i][j] / cnt[de] * getDy(n-i, m-j);
			now = min(now, val[de]);
		}
		res += now;
	}
	//	printf("%d %d : %lf\n", n, m, res);
	return res;
}
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &D, &N, &M);
		dice();
		for(int i=0; i<=N; i++) for(int j=0; j<=M; j++)
			Dy[i][j] = 0, Visit[i][j] = false;
		printf("%.10lf\n", getDy(N, M));
	}
	return 0;
}