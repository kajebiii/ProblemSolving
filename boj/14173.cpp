#include <stdio.h>
#include <algorithm>

using namespace std;

const int fre = 0;
int main() {
	if(fre) freopen("square.in", "r", stdin);
	if(fre) freopen("square.out", "w", stdout);
	int Nr[2][4];
	for(int k=0; k<2; k++) for(int i=0; i<4; i++) scanf("%d", &Nr[k][i]);
	int xM = max(Nr[0][2], Nr[1][2]), xm = min(Nr[0][0], Nr[1][0]);
	int yM = max(Nr[0][3], Nr[1][3]), ym = min(Nr[0][1], Nr[1][1]);
	int l = max(xM - xm, yM - ym);
	printf("%d\n", l * l);
	return 0;
}