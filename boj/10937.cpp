#include <stdio.h>
int n;
int dy[20][20][9222];
int score[99][99];
char dobo[20][20];

void setting() {
	int i;
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%s", &dobo[i]);
	}
	score['A']['A']=100;score['B']['B']=50;score['C']['C']=20;
	score['A']['B']=score['B']['A']=70;
	score['A']['C']=score['C']['A']=40;
	score['C']['B']=score['B']['C']=30;
}
int letsfind(int px, int py, int chk) {
	if(py==n) {
		return letsfind(px+1,0,chk);
	}
	if(px==n) {
		return 0;
	}
	if(!dy[px][py][chk]) {
		if(chk%2) dy[px][py][chk]=letsfind(px,py+1,chk/2);
		else{
			int l=0;
			if(py+1<n && (chk>>1)%2==0) l=(letsfind(px,py+1,chk/2+1)+score[dobo[px][py]][dobo[px][py+1]]);
			if(dy[px][py][chk]<l) dy[px][py][chk]=l;
			if(px+1<n) l=(letsfind(px,py+1,chk/2+(1<<(n-1)))+score[dobo[px][py]][dobo[px+1][py]] );
			if(dy[px][py][chk]<l) dy[px][py][chk]=l;
			l=letsfind(px,py+1,chk/2);
			if(dy[px][py][chk]<l) dy[px][py][chk]=l;
		}
	}
	return dy[px][py][chk];
}
int main() {
	setting();
	printf("%d",letsfind(0,0,0));
	return 0;
}