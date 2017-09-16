#include <stdio.h>

int M, N;
int Map[1111][1111];

int Q[1111111][3];
int All;

void INPUT() {
	scanf("%d %d", &M, &N);
	All=N*M;
	int i, j;
	for(i=1; i<=N; i++) for(j=1; j<=M; j++) {
		scanf("%d", &Map[i][j]);
		if(Map[i][j]==-1) All--;
	}
	for(i=1; i<=N; i++) Map[i][0]=Map[i][M+1]=-1;
	for(i=1; i<=M; i++) Map[0][i]=Map[N+1][i]=-1;
	return;
}
void PROCESS() {
	int r=0, f=0, i, j;
	for(i=1; i<=N; i++) for(j=1; j<=M; j++)
		if(Map[i][j]==1) {
			++r;
			Q[r][0]=i;
			Q[r][1]=j;
			Q[r][2]=0;
		}
	int x, y, z=0, new_x, new_y;
	int change_x[4]={0, 1, 0, -1};
	int change_y[4]={1, 0, -1, 0};
	while(f<r) {
		++f;
		x=Q[f][0];
		y=Q[f][1];
		z=Q[f][2];

		for(i=0; i<4; i++) {
			new_x=change_x[i]+x;
			new_y=change_y[i]+y;
			if(Map[new_x][new_y]==0) {
				Map[new_x][new_y]=1;
				++r;
				Q[r][0]=new_x;
				Q[r][1]=new_y;
				Q[r][2]=z+1;
			}
		}

	}

	if(All==r) printf("%d", z);
	else printf("-1");

	return;
}

int main() {
	INPUT();
	PROCESS();
}
