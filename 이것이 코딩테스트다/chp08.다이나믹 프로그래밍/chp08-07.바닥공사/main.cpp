#include <bits/stdc++.h>
#define DIVIDENUM 796796
using namespace std;

int N;
int d[1001];

int main() {
	cin >> N;

	d[1] = 1;
	d[2] = 3;
	for (int i = 3; i <= N; i++) {
		d[i] = (d[i - 2] * 2 + d[i - 1]) % DIVIDENUM;
	}
	
	cout << d[N] << endl;
	return 0;
}