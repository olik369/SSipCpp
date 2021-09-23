#include <bits/stdc++.h>

using namespace std;

long long d[100];

int main() {
	d[1] = 1;
	d[2] = 1;
	int n = 50;	//50번째 피보나치 수를 계산

	//피보나치 함수(반복문으로 구현, 바텀업 방식)
	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}

	cout << d[n] << endl;
	
	return 0;
}