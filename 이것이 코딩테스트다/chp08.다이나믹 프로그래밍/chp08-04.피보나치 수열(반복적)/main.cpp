#include <bits/stdc++.h>

using namespace std;

long long d[100];

int main() {
	d[1] = 1;
	d[2] = 1;
	int n = 50;	//50��° �Ǻ���ġ ���� ���

	//�Ǻ���ġ �Լ�(�ݺ������� ����, ���Ҿ� ���)
	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}

	cout << d[n] << endl;
	
	return 0;
}