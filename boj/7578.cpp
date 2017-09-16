#include <stdio.h>

int N;
int P;
int Line[505505];
int Check[1001001];

void INPUT() {
	scanf("%d", &N);
	int i, temp;
	for(P=1; P<N; P<<=1);
	for(i=0; i<N; i++) {
		scanf("%d", &temp);
		Check[temp]=i;
	}
	for(i=0; i<N; i++) {
		scanf("%d", &temp);
		Line[i]=Check[temp];
	}
	return;
}
int Heap[2001001];
void Update(int z) {
	while(z!=0) {
		Heap[z]=Heap[z*2  ]+Heap[z*2+1];
		z/=2;
	}
}
long long Sum(int x, int y) {
	long long result=0;
	while(x<=y) {
		if(x%2==1) {
			result+=Heap[x];
			x++;
		}
		if(y%2==0) {
			result+=Heap[y];
			y--;
		}
		x/=2;
		y/=2;
	}
	return result;
}
void PROCESS() {
	int i;
	long long ans=0;
	for(i=N-1; i>=0; i--) {
		ans+=Sum(P+0, P+Line[i]);
		Heap[P+Line[i]]++;
		Update((P+Line[i])/2);
	}
	printf("%lld", ans);
	return;
}

int main() {
	INPUT();
	PROCESS();
	return 0;
}
