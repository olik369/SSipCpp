#include <bits/stdc++.h>

using namespace std;

//계산된 결과를 저장하기 위한 배열
long long d[100];

long long fibo(int x) {
	if (x == 1 || x == 2) {
		return 1;
	}

	//이미 계산한 적 있는 문제라면 그대로 반환
	if (d[x] != 0) {
		return d[x];
	}
	else {
		d[x] = fibo(x - 1) + fibo(x - 2);
		return d[x];
	}
}

int main() {
	cout << fibo(60) << endl;

	return 0;
}