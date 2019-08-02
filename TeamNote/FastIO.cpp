static char _buffer[1 << 19];
static int _currentChar = 0;
static int _charsNumber = 0;

static inline int _read() {
	if(_charsNumber < 0) {
		exit(1);
	}
	if(!_charsNumber || _currentChar == _charsNumber) {
		_charsNumber = (int)fread(_buffer, sizeof(_buffer[0]), sizeof(_buffer), stdin);
		_currentChar = 0;
	}
	if(_charsNumber <= 0) {
		return -1;
	}
	return _buffer[_currentChar++];
}

static inline int _readInt() {
	int c, x, s;
	c = _read();
	while(c <= 32) c = _read();
	x = 0;
	s = 1;
	if(c == '-') {
		s = -1;
		c = _read();
	}
	while(c > 32) {
		x *= 10;
		x += c - '0';
		c = _read();
	}
	if(s < 0) x = -x;
	return x;
}

//IOI
static char _buffer[1024];
static int _currentChar = 0;
static int _charsNumber = 0;

static inline int _read() {
	if(_charsNumber < 0) {
		exit(1);
	}
	if(!_charsNumber || _currentChar == _charsNumber) {
		_charsNumber = (int)fread(_buffer, sizeof(_buffer[0]), sizeof(_buffer), stdin);
		_currentChar = 0;
	}
	if(_charsNumber <= 0) {
		return -1;
	}
	return _buffer[_currentChar++];
}

static inline int _readInt() {
	int c, x, s;
	c = _read();
	while(c <= 32) c = _read();
	x = 0;
	s = 1;
	if(c == '-') {
		s = -1;
		c = _read();
	}
	while(c > 32) {
		x *= 10;
		x += c - '0';
		c = _read();
	}
	if(s < 0) x = -x;
	return x;
}



//yclock

#include <stdio.h>
#include <algorithm>
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);
using namespace std;
static unsigned char str[3600055], *p=str;
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);

int N, M;
int main() {
	fread(str, 1, 3600055, stdin);
	rf(N) for(int i = 0; i < N; i++) { rf(A[i] first) A[i].second = i; }
	rf(M) for(int i = 0; i < M; i++) ques[i] init(i);
	sort(A  A+N); sort(ques, ques+M);
	for(int i = 0, j = 0; i < M; i++) {
		for(; j < N && A[j] first <= ques[i] c; j++) upBIT(A[j].second+1);
		Ans[ques[i] idx] = (ques[i].e-ques[i].s+1) - (getBIT(ques[i].e) - getBIT(ques[i].s-1));
	}
	for(int i = 0; i < M; i++) printf("%d\n", Ans[i]);
	return 0;
}
